# CAdoEvents Class

The `CAdoEvents` class serves as a comprehensive event-handling interface for ActiveX Data Objects (ADO) within the `AfxNova` framework. It is designed to intercept and respond to a wide range of `ADO` operations, offering developers fine-grained control over database interactions at runtime.

This class encapsulates both **Connection** events and **Recordset** events, enabling developers to monitor and manipulate the behavior of `ADO` objects during critical operations such as connecting to a data source, executing commands, navigating records, and modifying data. Each event method provides access to relevant parameters and status flags, allowing for custom logic to be injected before or after the underlying `ADO` operation.

For example, the **WillMove** event is triggered just before the current position in a **Recordset** changes, giving developers a chance to validate or cancel the move operation based on business rules or application state.

Whether you're building robust data-driven applications or need to enforce strict transactional workflows, `CAdoEvents` offers the hooks necessary to make your `ADO` interactions both intelligent and responsive.

####Usage example

```
#include once "AfxNova/CADODB.inc"
USING AfxNova

' ########################################################################################
' // Custom implementation of ADO Connection events
' ########################################################################################
TYPE CAdoConnectionEventsImpl EXTENDS CAdoConnectionEvents
   DECLARE FUNCTION WillConnect (BYVAL ConnectionString AS Afx_BSTR PTR, BYVAL UserID AS Afx_BSTR PTR, BYVAL Password AS Afx_BSTR PTR, BYVAL Options AS LONG PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   DECLARE FUNCTION ConnectComplete (BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   DECLARE FUNCTION Disconnect (BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   ' Override any additional method that you wish
END TYPE

FUNCTION CAdoConnectionEventsImpl.WillConnect (BYVAL ConnectionString AS Afx_BSTR PTR, BYVAL UserID AS Afx_BSTR PTR, BYVAL Password AS Afx_BSTR PTR, BYVAL Options AS LONG PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   CADODB_DP("- Connection string: " & **ConnectionString)
   RETURN S_OK   ' change it if needed
END FUNCTION
FUNCTION CAdoConnectionEventsImpl.ConnectComplete (BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   CADODB_DP("- adStatus: " & WSTR(*adStatus))
   IF *adStatus = adStatusOK THEN
      CADODB_DP("Connection succeeded")
   ELSE
      CADODB_DP("Connection failed")
   END IF
   RETURN S_OK   ' change it if needed
END FUNCTION
FUNCTION CAdoConnectionEventsImpl.Disconnect (BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
   CADODB_DP("")
   RETURN S_OK   ' change it if needed
END FUNCTION
' ########################################################################################

' ########################################################################################
' // Custom implementation of ADO Recordset events
' ########################################################################################
TYPE CAdoRecordsetEventsImpl EXTENDS CAdoRecordsetEvents
   DECLARE FUNCTION WillMove (BYVAL adReason AS EventReasonEnum, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   DECLARE FUNCTION MoveComplete (BYVAL adReason AS EventReasonEnum, BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   DECLARE FUNCTION EndOfRecordset (BYVAL fMoreData AS VARIANT_BOOL PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   ' Override any additional method that you wish
END TYPE

FUNCTION CAdoRecordsetEventsImpl.WillMove (BYVAL adReason AS EventReasonEnum, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   CADODB_DP("")
   RETURN S_OK   ' change it if needed
END FUNCTION
FUNCTION CAdoRecordsetEventsImpl.MoveComplete (BYVAL adReason AS EventReasonEnum, BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   CADODB_DP("")
   RETURN S_OK   ' change it if needed
END FUNCTION
FUNCTION CAdoRecordsetEventsImpl.EndOfRecordset (BYVAL fMoreData AS VARIANT_BOOL PTR, BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
   CADODB_DP("")
   RETURN S_OK   ' change it if needed
END FUNCTION
' ########################################################################################

' // === Create an instance of the Connection object
DIM pConnection AS CAdoConnection
' // === Connect events
DIM pEvtSink AS ANY PTR = NEW CAdoConnectionEventsImpl
pConnection.SetEvents pEvtSink
' // === Open the connection
pConnection.Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb")

' // === Create a Recordset object
DIM pRecordset AS CAdoRecordset
' // === Connect events
pEvtSink = NEW CAdoRecordsetEventsImpl
pRecordset.SetEvents pEvtSink
' // === Open the recordset
pRecordset.Open("SELECT * FROM Authors", pConnection, adOpenKeyset, adLockOptimistic, adCmdText)

' // === Parse the recordset
' // While not at the end of the recordset...
DO WHILE NOT pRecordset.EOF
   ' // Get the content of the "Author" column
   PRINT pRecordset.Collect("Author")
   ' // Fetch the next row
   IF pRecordset.MoveNext <> S_OK THEN EXIT DO
LOOP

' // === Close the recordset and the connection
' // If you don't close them, they will be closed when the application ends
pRecordset.Close
pConnection.Close
```

# Connection events

| Name       | Description |
| ---------- | ----------- |
| [BeginTransComplete](#begintranscomplete) | Called after the **BeginTrans** operation. |
| [CommitTransComplete](#committranscomplete) | Called after the **CommitTrans** operation. |
| [ConnectComplete](#connectcomplete) | Called after a connection starts. |
| [DisConnect](#disconnect) | Called after a connection ends. |
| [ExecuteComplete](#executecomplete) | Called after a command has finished executing. |
| [InfoMessage](#infomessage) | Called whenever a warning occurs during a **ConnectionEvent** operation. |
| [RollbackTransComplete](#rollabcktranscomplete) | Called after the **RollbackTrans** operation. |
| [WillConnect](#willconnect) | Called before a connection starts. |
| [WillExecute](#willexecute) | Called just before a pending command executes on this connection and affords the user an opportunity to examine and modify the pending execution parameters. |

---

# Recordset events

| Name       | Description |
| ---------- | ----------- |
| [EndOfRecordset](#endofrecordset) | Called when there is an attempt to move to a row past the end of the **Recordset**. |
| [FetchComplete](#fetchcomplete) | Called after all the records in a lengthy asynchronous operation have been retrieved into the **Recordset**. |
| [FetchProgress](#fetchprogress) | Called periodically during a lengthy asynchronous operation to report how many rows have currently been retrieved into the **Recordset**. |
| [FieldChangeComplete](#fieldchangecomplete) | Called after the value of one or more Field objects has changed. |
| [MoveComplete](#movecomplete) | Called after the current position in the **Recordset** changes. |
| [RecordChangeComplete](#recordchangecomplete) | Called after one or more records change. |
| [RecordsetChangeComplete](#recordsetchangecomplete) | Called after the **Recordset** has changed. |
| [WillChangeField](#willchangefield) | Called before a pending operation changes the value of one or more **Field** objects in the **Recordset**. |
| [WillChangeRecord](#willchangerecord) | Called before one or more records (rows) in the **Recordset** change. |
| [WillChangeRecordset](#willchangerecordset) | Called before a pending operation changes the **Recordset**. |
| [WillMove](#willmove) | The **WillMove** event is called before a pending operation changes the current position in the **Recordset**. |

---

### WillConnect

Called before a connection starts.

```
FUNCTION WillConnect (BYVAL ConnectionString AS Afx_BSTR PTR, BYVAL UserID AS Afx_BSTR PTR, _
   BYVAL Password AS Afx_BSTR PTR, BYVAL Options AS LONG PTR, BYVAL adStatus AS EventStatusEnum PTR, _
   BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *ConnectionString* | A BSTR that contains connection information for the pending connection. |
| *UserID* | A BSTR that contains a user name for the pending connection. |
| *Password* | A BSTR that contains a password for the pending connection. |
| *Options* | A Long value that indicates how the provider should evaluate the *ConnectionString*. Your only option is *adAsyncOpen*. |
| *adStatus* | *EventStatusEnum*. When this event is called, this parameter is set to *adStatusOK* by default. It is set to *adStatusCantDeny* if the event cannot request cancellation of the pending operation.Before this event returns, set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications. Set this parameter to *adStatusCancel* to request the connection operation that caused cancellation of this notification. |
| *pConnection* | The **Connection** object for which this event notification applies. Changes to the parameters of the **Connection** by the **WillConnect** event handler will have no effect on the **Connection**. |

#### Remarks

When **WillConnect** is called, the *ConnectionString*, *UserID*, *Password*, and *Options* parameters are set to the values established by the operation that caused this event (the pending connection), and can be changed before the event returns. WillConnect may return a request that the pending connection be canceled.

When this event is canceled, **ConnectComplete** will be called with its *adStatus* parameter set to *adStatusErrorsOccurred*.

---

### ConnectComplete

The **ConnectComplete** event is called after a connection starts.

```
FUNCTION ConnectComplete (BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, _
   BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *pError* | An **Error** object. It describes the error that occurred if the value of *EventStatusEnum* is *adStatusErrorsOccurred*; otherwise, it is not set. |
| *adStatus* | *EventStatusEnum*. When **ConnectComplete** is called, this parameter is set to *adStatusCancel* if a **WillConnect** event has requested cancellation of the pending connection. Before either event returns, set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications. However, closing and reopening the **Connection** causes these events to occur again. |
| *pConnection* | The **Connection** object that fired the event. |

---

### Disconnect

Called after a connection ends.

```
FUNCTION Disconnect (BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *adStatus* | An *EventStatusEnum* value indicating the success or failure of the operation that triggered the event. |
| *pConnection* | The **Connection** object that fired the event. |

---

### WillExecute

Called ust before a pending command executes on a connection.

```
FUNCTION WillExecute (BYVAL Source AS Afx_BSTR PTR, BYVAL CursorType AS CursorTypeEnum PTR, _
   BYVAL LockType AS LockTypeEnum PTR, BYVAL Options AS LONG PTR, BYVAL adStatus AS EventStatusEnum PTR, _
   BYVAL pCommand AS Afx_ADOCommand PTR, BYVAL pRecordset AS Afx_ADORecordset PTR, _
   BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *Source* | A BSTR that contains an SQL command or a stored procedure name. |
| *CursorType* | 	A *CursorTypeEnum* that contains the type of cursor for the **Recordset** that will be opened. With this parameter, you can change the cursor to any type during a **Recordset** Open operation. *CursorType* will be ignored for any other operation. |
| *LockType* | A *LockTypeEnum* that contains the lock type for the **Recordset** that will be opened. With this parameter, you can change the lock to any type during a **Recordset** Open operation. LockType will be ignored for any other operation. |
| *Options* | A Long value that indicates options that can be used to execute the command or open the **Recordset**. |
| *adStatus* | *EventStatusEnum*. Before this event returns, set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications, or *adStatusCancel* to request cancellation of the operation that caused this event. |
| *pCommand* | The **Command** object for which this event notification applies. |
| *pRecordset* | The **Recordset** object for which this event notification applies. |
| *pConnection* | The **Connection** object for which this event notification applies. |

#### Remarks

A **WillExecute** event may occur due to a **Connection.Execute**, **Command.Execute**, or **Recordset.Open** method The *pConnection* parameter should always contain a valid reference to a **Connection** object. If the event is due to **Connection.Execute**, the *pRecordset* and *pCommand* parameters are set to Nothing. If the event is due to Recordset.Open, the pRecordset parameter will reference the Recordset object and the pCommand parameter is set to NULL. If the event is due to **Command.Execute**, the *pCommand* parameter will reference the **Command** object and the *pRecordset* parameter is set to NULL.

**WillExecute** allows you to examine and modify the pending execution parameters. This event may return a request that the pending command be canceled.

---

### ExecuteComplete

Called after a command has finished executing.

```
FUNCTION ExecuteComplete (BYVAL RecordsAffected AS LONG, BYVAL pError AS Afx_ADOError PTR, _
   BYVAL adStatus AS EventStatusEnum PTR, BYVAL pCommand AS Afx_ADOCommand PTR, _
   BYVAL pRecordset AS Afx_ADORecordset PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *RecordsAffected* | A Long value indicating the number of records affected by the command. |
| *pError* | An **Error** object. It describes the error that occurred if the value of *adStatus* is *adStatusErrorsOccurred*; otherwise it is not set. |
| *adStatus* | *EventStatusEnum*. Before this event returns, set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications. |
| *pCommand* | The **Command** object that was executed. Contains a **Command** object even when calling **Connection.Execute** or **Recordset.Open** without explicitly creating a **Command**, in which cases the **Command** object is created internally by ADO. |
| *pRecordset* | A **Recordset** object that is the result of the executed command. This **Recordset** may be empty. You should never destroy this **Recordset** object from within this event handler. Doing so will result in an Access Violation when ADO tries to access an object that no longer exists. |
| *pConnection* | A **Connection** object. The connection over which the operation was executed. |

#### Remarks

An **ExecuteComplete** event may occur due to the **Connection.Execute**, **Command.Execute**, **Recordset.Open**, **Recordset.Requery**, or **Recordset.NextRecordset** methods.

---

### InfoMessage

Called whenever a warning occurs during a ConnectionEvent operation.

```
FUNCTION InfoMessage (BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, _
   BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
```
| Parameter  | Description |
| ---------- | ----------- |
| *pError* | An **Error** object. This parameter contains any errors that are returned. If multiple errors are returned, enumerate the **Errors** collection to find them. |
| *adStatus* | *EventStatusEnum*. Before this event returns, set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications. |
| *pConnection* | A **Connection** object. The connection for which the warning occurred. For example, warnings can occur when opening a **Connection** object or executing a **Command** on a **Connection**. |

---

### BeginTransComplete

Called after the **BeginTrans** operation.

```
FUNCTION BeginTransComplete (BYVAL TransactionLevel AS LONG, BYVAL pError AS Afx_ADOError PTR, _
   BYVAL adStatus AS EventStatusEnum PTR, BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *TransactionLevel* | A Long value that contains the new transaction level of the **BeginTrans** that caused this event. |
| *pError* | An **Error** object. It describes the error that occurred if the value of *EventStatusEnum* is *adStatusErrorsOccurred*; otherwise, it is not set. |
| *adStatus* | *EventStatusEnum*. Subsequent notifications can be prevented by setting this parameter to *adStatusUnwantedEvent* before the event returns. |
| *pConnection* | The **Connection** object for which this event occurred. |

---

### CommitTransComplete

Called after the **CommitTrans** operation.

```
FUNCTION CommitTransComplete (BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, _
   BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pError* | An **Error** object. It describes the error that occurred if the value of *EventStatusEnum* is *adStatusErrorsOccurred*; otherwise, it is not set. |
| *adStatus* | *EventStatusEnum*. Subsequent notifications can be prevented by setting this parameter to *adStatusUnwantedEvent* before the event returns. |
| *pConnection* | The **Connection** object for which this event occurred. |

---

### RollbackTransComplete

Called after the **RollbackTrans** operation.

```
FUNCTION RollbackTransComplete (BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, _
   BYVAL pConnection AS Afx_ADOConnection PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pError* | An **Error** object. It describes the error that occurred if the value of *EventStatusEnum* is *adStatusErrorsOccurred*; otherwise, it is not set. |
| *adStatus* | *EventStatusEnum*. Subsequent notifications can be prevented by setting this parameter to *adStatusUnwantedEvent* before the event returns. |
| *pConnection* | The **Connection** object for which this event occurred. |

---

### WillChangeField

Called before a pending operation changes the value of one or more **Field** objects in the **Recordset**.

```
FUNCTION WillChangeField (BYVAL cFields AS LONG, BYVAL Fields AS VARIANT, _
   BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cFields* | A Long that indicates the number of **Field** objects in **Fields**. |
| *Fields* | For **WillChangeField**, the **Fields** parameter is an array of Variants that contains **Field** objects with the original values. |
| *adStatus* |	*EventStatusEnum*. When **WillChangeField** is called, this parameter is set to *adStatusOK* if the operation that caused the event was successful. It is set to *adStatusCantDeny* if this event cannot request cancellation of the pending operation. Before **WillChangeField** returns, set this parameter to *adStatusCancel* to request cancellation of the pending operation. |
| *pRecordset* | A **Recordset** object. The **Recordset** for which this event occurred. |

#### Remarks

A **WillChangeField** or **FieldChangeComplete** event may occur when setting the Value property and calling the **Update** method with field and value array parameters.

---

### FieldChangeComplete 

Called after the value of one or more **Field** objects has changed.

```
FUNCTION FieldChangeComplete (BYVAL cFields AS LONG, BYVAL Fields AS VARIANT, _
   BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, _
   BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cFields* | A Long that indicates the number of **Field** objects in **Fields**. |
| *Fields* | For **FieldChangeComplete**, the **Fields** parameter is an array of Variants that contains **Field** objects with the changed values. |
| *pError* | An **Error** object. It describes the error that occurred if the value of *adStatus* is *adStatusErrorsOccurred*; otherwise it is not set. |
| *adStatus* |	*EventStatusEnum*. When **FieldChangeComplete** is called, this parameter is set to *adStatusOK* if the operation that caused the event was successful, or to *adStatusErrorsOccurred* if the operation failed. Before **FieldChangeComplete** returns, set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications. |
| *pRecordset* | A **Recordset** object. The **Recordset** for which this event occurred. |

#### Remarks

A **WillChangeField** or **FieldChangeComplete** event may occur when setting the Value property and calling the **Update** method with field and value array parameters.

---

### WillChangeRecord

Called before one or more records (rows) in the **Recordset** change.

```
FUNCTION WillChangeRecord (BYVAL adReason AS EventReasonEnum, BYVAL cRecords AS LONG, _
   BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *adReason* | An *EventReasonEnum* value that specifies the reason for this event. Its value can be *adRsnAddNew*, *adRsnDelete*, *adRsnUpdate*, *adRsnUndoUpdate*, *adRsnUndoAddNew*, *adRsnUndoDelete*, or *adRsnFirstChange*. |
| *cRecords* | A Long value that indicates the number of records changing (affected). |
| *adStatus* | *EventStatusEnum*. When **WillChangeRecord** is called, this parameter is set to *adStatusOK* if the operation that caused the event was successful. It is set to *adStatusCantDeny* if this event cannot request cancellation of the pending operation. Before **WillChangeRecord** returns, set this parameter to *adStatusCancel* to request cancellation of the operation that caused this event or set this parameter to *adStatusUnwantedEvent* to prevent subsequent notications. |
| *pRecordset* | A **Recordset** object. The **Recordset** for which this event occurred. |

#### Remarks

A **WillChangeRecord** or **RecordChangeComplete** event may occur for the first changed field in a row due to the following **Recordset** operations: **Update**, **Delete**, **CancelUpdate**, **AddNew**, **UpdateBatch**, and **CancelBatch**. The value of the **Recordset** *CursorType* determines which operations cause the events to occur.

During the **WillChangeRecord** event, the **Recordset** **Filter** property is set to *adFilterAffectedRecords*. You cannot change this property while processing the event.

You must set the *adStatus* parameter to *adStatusUnwantedEvent* for each possible *adReason* value in order to completely stop event noticiation for any event that includes an *adReason* parameter.

---

### RecordChangeComplete

Called after one or more records change.

```
FUNCTION RecordChangeComplete (BYVAL adReason AS EventReasonEnum, BYVAL cRecords AS LONG, _
   BYVAL pError AS Afx_ADOError PTR, BYVAL adStatus AS EventStatusEnum PTR, _
   BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *adReason* | An *EventReasonEnum* value that specifies the reason for this event. Its value can be *adRsnAddNew*, *adRsnDelete*, *adRsnUpdate*, *adRsnUndoUpdate*, *adRsnUndoAddNew*, *adRsnUndoDelete*, or *adRsnFirstChange*. |
| *cRecords* | A Long value that indicates the number of records changing (affected). |
| *pError* | An **Error** object. It describes the error that occurred if the value of *adStatus* is *adStatusErrorsOccurred*; otherwise it is not set. |
| *adStatus* | *EventStatusEnum*. When **RecordChangeComplete** is called, this parameter is set to *adStatusOK* if the operation that caused the event was successful, or to *adStatusErrorsOccurred* if the operation failed. Before **RecordChangeComplete** returns, set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications. |
| *pRecordset* | A **Recordset** object. The **Recordset** for which this event occurred. |

#### Remarks

A **WillChangeRecord** or **RecordChangeComplete** event may occur for the first changed field in a row due to the following **Recordset** operations: **Update**, **Delete**, **CancelUpdate**, **AddNew**, **UpdateBatch**, and **CancelBatch**. The value of the **Recordset** *CursorType* determines which operations cause the events to occur.

During the **WillChangeRecord** event, the **Recordset** **Filter** property is set to *adFilterAffectedRecords*. You cannot change this property while processing the event.

You must set the *adStatus* parameter to *adStatusUnwantedEvent* for each possible *adReason* value in order to completely stop event noticiation for any event that includes an *adReason* parameter.

---

### WillChangeRecordset

Called before a pending operation changes the **Recordset**.

```
FUNCTION WillChangeRecordset (BYVAL adReason AS EventReasonEnum, _
   BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *adReason* | An *EventReasonEnum* value that specifies the reason for this event. Its value can be *adRsnRequery*, *adRsnResynch*, *adRsnClose*, *adRsnOpen*. |
| *adStatus* | *EventStatusEnum*. When **WillChangeRecordset** is called, this parameter is set to *adStatusOK* if the operation that caused the event was successful. It is set to *adStatusCantDeny* if this event cannot request cancellation of the pending operation. Before **WillChangeRecordset** returns, set this parameter to *adStatusCancel* to request cancellation of the pending operation or set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications. |
| *pRecordset* | A **Recordset** object. The **Recordset** for which this event occurred. |

#### Remarks

A **WillChangeRecordset** or **RecordsetChangeComplete** event may occur due to the **Recordset** **Requery** or **Open** methods.

If the provider does not support bookmarks, a **RecordsetChange** event notification occurs each time new rows are retrieved from the provider. The frequency of this event depends on the **RecordsetCacheSize** property.

You must set the *adStatus* parameter to *adStatusUnwantedEvent* for each possible *adReason* value in order to completely stop event notification for any event that includes an *adReason* parameter.

---

### RcordsetChangeComplete

Called after the **Recordset** has changed.

```
FUNCTION RecordsetChangeComplete (BYVAL adReason AS EventReasonEnum, BYVAL pError AS Afx_ADOError PTR, _
   BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *adReason* | An *EventReasonEnum* value that specifies the reason for this event. Its value can be *adRsnRequery*, *adRsnResynch*, *adRsnClose*, *adRsnOpen*. |
| *pError* | An **Error** object. It describes the error that occurred if the value of *adStatus* is *adStatusErrorsOccurred*; otherwise it is not set. |
| *adStatus* | *EventStatusEnum*. When **RecordsetChangeComplete** is called, this parameter is set to *adStatusOK* if the operation that caused the event was successful, *adStatusErrorsOccurred* if the operation failed, or *adStatusCancel* if the operation associated with the previously accepted **WillChangeRecordset** event has been canceled. Before **WillChangeRecordset** or **RecordsetChangeComplete** returns, set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications. |
| *pRecordset* | A **Recordset** object. The **Recordset** for which this event occurred. |

#### Remarks

A **WillChangeRecordset** or **RecordsetChangeComplete** event may occur due to the **Recordset** **Requery** or **Open** methods.

If the provider does not support bookmarks, a **RecordsetChange** event notification occurs each time new rows are retrieved from the provider. The frequency of this event depends on the **RecordsetCacheSize** property.

You must set the *adStatus* parameter to *adStatusUnwantedEvent* for each possible *adReason* value in order to completely stop event notification for any event that includes an *adReason* parameter.

---

### WillMove

Called before a pending operation changes the current position in the **Recordset**.

```
FUNCTION WillMove (BYVAL adReason AS EventReasonEnum, BYVAL adStatus AS EventStatusEnum PTR, _
   BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *adReason* | An *EventReasonEnum* value that specifies the reason for this event. Its value can be *adRsnMoveFirst*, *adRsnMoveLast*, *adRsnMoveNext*, *adRsnMovePrevious*, *adRsnMove*, or *adRsnRequery*. |
| *adStatus* | *EventStatusEnum*. When **WillMove** is called, this parameter is set to *adStatusOK* if the operation that caused the event was successful. It is set to *adStatusCantDeny* if this event cannot request cancellation of the pending operation. Before **WillMove** returns, set this parameter to *adStatusCancel* to request cancellation of the pending operation or set this parameter to *adStatusUnwantedEvent* to prevent subsequent notications. |
| *pRecordset* | A **Recordset** object. The **Recordset** for which this event occurred. |

#### Remarks

A **WillMove** or **MoveComplete** event may occur due to the following Recordset operations:

* Open
* Move
* MoveFirst
* MoveLast
* MoveNext
* MovePrevious
* AddNew
* Requery

These events may occur because of the following properties:

* Filter
* Index
* Bookmark
* AbsolutePage
* AbsolutePosition

These events also occur if a child Recordset has **Recordset** events connected and the parent **Recordset** is moved.

You must set the *adStatus* parameter to *adStatusUnwantedEvent* for each possible *adReason* value in order to completely stop event notification for any event that includes an *adReason* parameter.

---

### MoveComplete

Called after the current position in the **Recordset** changes.

```
FUNCTION MoveComplete (BYVAL adReason AS EventReasonEnum, BYVAL pError AS Afx_ADOError PTR, _
   BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *adReason* | An *EventReasonEnum* value that specifies the reason for this event. Its value can be *adRsnMoveFirst*, *adRsnMoveLast*, *adRsnMoveNext*, *adRsnMovePrevious*, *adRsnMove*, or *adRsnRequery*. |
| *pError* | An **Error** object. It describes the error that occurred if the value of *adStatus* is *adStatusErrorsOccurred*; otherwise it is not set. |
| *adStatus* | *EventStatusEnum*. When **MoveComplete** is called, this parameter is set to *adStatusOK* if the operation that caused the event was successful, or to *adStatusErrorsOccurred* if the operation failed. Before **MoveComplete** returns, set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications. |
| *pRecordset* | A **Recordset** object. The **Recordset** for which this event occurred. |

#### Remarks

A **WillMove** or **MoveComplete** event may occur due to the following Recordset operations:

* Open
* Move
* MoveFirst
* MoveLast
* MoveNext
* MovePrevious
* AddNew
* Requery

These events may occur because of the following properties:

* Filter
* Index
* Bookmark
* AbsolutePage
* AbsolutePosition

These events also occur if a child Recordset has **Recordset** events connected and the parent **Recordset** is moved.

You must set the *adStatus* parameter to *adStatusUnwantedEvent* for each possible *adReason* value in order to completely stop event notification for any event that includes an *adReason* parameter.

---

### EndOfRecordset

Called when there is an attempt to move to a row past the end of the **Recordset**.

```
FUNCTION EndOfRecordset (BYVAL fMoreData AS VARIANT_BOOL PTR, _
   BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *fMoreData* | A VARIANT_BOOL value that, if set to VARIANT_TRUE, indicates more rows have been added to the **Recordset**. |
| *adStatus* | *EventStatusEnum*. When **EndOfRecordset** is called, this parameter is set to *adStatusOK* if the operation that caused the event was successful. It is set to *adStatusCantDeny* if this event cannot request cancellation of the operation that caused this event. Before **EndOfRecordset** returns, set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications. |
| *pRecordset* | A **Recordset** object. The **Recordset** for which this event occurred. |

#### Remarks

An **EndOfRecordset** event may occur if the **MoveNext** operation fails.

This event handler is called when an attempt is made to move past the end of the **Recordset** object, perhaps as a result of calling **MoveNext**. However, while in this event, you could retrieve more records from a database and append them to the end of the **Recordset**. In that case, set *fMoreData* to VARIANT_TRUE, and return from **EndOfRecordset**. Then call **MoveNext** again to access the newly retrieved records.

---

### FetchProgress

Called periodically during a lengthy asynchronous operation to report how many more rows have currently been retrieved into the **Recordset**.

```
FUNCTION FetchProgress (BYVAL Progress AS LONG, BYVAL MaxProgress AS LONG, _
   BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *Progress* | A Long value indicating the number of records that have currently been retrieved by the fetch operation. |
| *MaxProgress* | A Long value indicating the maximum number of records expected to be retrieved. |
| *adStatus* | An *EventStatusEnum* status value. |
| *pRecordset* | A **Recordset** object that is the object for which the records are being retrieved. |

#### Remarks

When using **FetchProgress** with a child **Recordset**, be aware that the Progress and *MaxProgress* parameter values are derived from the underlying Cursor Service rowset. The values returned represent the total number of records in the underlying rowset, not just the number of records in the current chapter.

---

### FetchComplete

Called after all the records in a lengthy asynchronous operation have been retrieved into the **Recordset**.

```
FUNCTION FetchComplete (BYVAL pError AS Afx_ADOError PTR, _
   BYVAL adStatus AS EventStatusEnum PTR, BYVAL pRecordset AS Afx_ADORecordset PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pError* | An **Error** object. It describes the error that occurred if the value of *adStatus* is *adStatusErrorsOccurred*; otherwise it is not set. |
| *adStatus* |	*EventStatusEnum*. Before this event returns, set this parameter to *adStatusUnwantedEvent* to prevent subsequent notifications. |
| *pRecordset* | A **Recordset** object. The object for which the records were retrieved. |

---
