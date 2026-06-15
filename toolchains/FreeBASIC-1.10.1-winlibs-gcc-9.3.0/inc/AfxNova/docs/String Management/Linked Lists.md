# DWStrList

`DWStrList`implements an indexed doubly-linked list for the `DWSTRING` (Unicode dynamic string) data type.

**Include file** : DWStrProcs.inc

#### Usage examples

Using the dotted syntax:

```
' // Build the linked list
DIM List AS DWStrList
List.Add("Result 1")
List.Add("Result 2")
List.Add("Result 3")
List.Insert(1, "New string")
List.Replace(2, "Replaced string")

' // Retrieve and print the results
FOR i AS LONG = 1 TO List.Count
   PRINT List.Item(i)
NEXT
```

Using NEW and the pointer syntax:

```
' // Build the linked list
DIM List AS DWStrList PTR = NEW DWStrList
List->Add("Result 1")
List->Add("Result 2")
List->Add("Result 3")
List->Insert(1, "New string")
List->Replace(2, "Replaced string")

' // Retrieve and print the results
FOR i AS LONG = 1 TO List->Count
   PRINT List->Item(i)
NEXT

' // Delete the list
Delete List
```
---

## Methods

| Name       | Description |
| ---------- | ----------- |
| [Add](#add) | Appends an item to the list. |
| [Clear](#clear) | Empties the entire list. |
| [Count](#count) | Returns the number of items in the list. |
| [Insert](#insert) | Inserts an item at the specific index. |
| [Item](#item) | Retrieves the item at the specified index. |
| [Remove](#remove) | Removes the specified item from the list. |
| [Replace](#replace) | Replaces the item at the specified index. |

---

# DVarList

`DVarList`implements an indexed doubly-linked list for the `DVARIANT` (dynamic variant) data type. A `DVARIANT` can contain any kind of data except fixed-length string data (if you pass it as the input it will be converted to a unicode dynamic string).

**Include file** : DVariant.inc

#### Usage examples

Using the dotted syntax:

```
' // Build the linked list
DIM List AS DVarList
List.Add("Result 1")
List.Add("Result 2")
List.Add("Result 3")
List.Insert(1, "New string")
List.Replace(2, "Replaced string")

' // Retrieve and print the results
FOR i AS LONG = 1 TO List.Count
   PRINT List.Item(i)
NEXT
```

Using NEW and the pointer syntax:

```
' // Build the linked list
DIM List AS DVarList PTR = NEW DVarList
List->Add("Result 1")
List->Add("Result 2")
List->Add("Result 3")
List->Insert(1, "New string")
List->Replace(2, "Replaced string")

' // Retrieve and print the results
FOR i AS LONG = 1 TO List->Count
   PRINT List->Item(i)
NEXT

' // Delete the list
Delete List
```
---

## Methods

| Name       | Description |
| ---------- | ----------- |
| [Add](#add2) | Appends an item to the list. |
| [Clear](#clear2) | Empties the entire list. |
| [Count](#count2) | Returns the number of items in the list. |
| [Insert](#insert2) | Inserts an item at the specific index. |
| [Item](#item2) | Retrieves the item at the specified index. |
| [Remove](#remove2) | Removes the specified item from the list. |
| [Replace](#replace2) | Replaces the item at the specified index. |

---

## <a name="add"></a>Add (DWStrList)

Appends a string to the list.

```
FUNCTION Add (BYREF dws AS DWSTRING) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *dws* | The string to append. |

#### Return value

Returns the number of items in the list.

---

## <a name="clear"></a>Clear (DWStrList)

Empties the entire list.

```
SUB Clear
```
---

## <a name="count"></a>Count (DWStrList)

Returns the number of items in the list.

```
FUNCTION Count () AS LONG
```

#### Return value

Returns the number of items in the list.

---

## <a name="insert"></a>Insert (DWStrList)

Inserts an item at the specific index.

```
FUNCTION Insert (BYVAL idx AS LONG, BYREF dws AS DWSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *idx* | The one-based index where to insert the item. |
| *dws* | The string to insert. |

#### Return value

If the method succeeds, it returns TRUE; otherwise, FALSE.

---

## <a name="item"></a>Item (DWStrList)

Retrieves the item at the specified index.

```
FUNCTION Item (BYVAL idx AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *idx* | The one-based index of the item to retrieve. |

#### Return value

If the method succeeds, it returns TRUE; otherwise, FALSE.

---

## <a name="remove"></a>Remove (DWStrList)

Removes the specified item from the list. Indexes are one-based.

```
FUNCTION Remove (BYVAL idx AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *idx* | The one-based index of the item to remove. |

#### Return value

If the method succeeds, it returns TRUE; otherwise, FALSE.

---

## <a name="replace"></a>Replace (DWStrList)

Replaces the item at the specified index.

```
FUNCTION Replace (BYVAL idx AS LONG, BYREF dws AS DWSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *idx* | The one-based index of the item to replace. |
| *dws* | The replacement string. |


#### Return value

If the method succeeds, it returns TRUE; otherwise, FALSE.

---

## <a name="add2"></a>Add (DVarList)

Appends a VARIANT to the list.

```
FUNCTION Add (BYREF dv AS DVARIANT) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *dv* | The VARIANT to append. |

#### Return value

Returns the number of items in the list.

---

## <a name="clear2"></a>Clear (DVarList)

Empties the entire list.

```
SUB Clear
```
---

## <a name="count2"></a>Count (DVarList)

Returns the number of items in the list.

```
FUNCTION Count () AS LONG
```

#### Return value

Returns the number of items in the list.

---

## <a name="insert2"></a>Insert (DVarList)

Inserts an item at the specific index.

```
FUNCTION Insert (BYVAL idx AS LONG, BYREF dv AS DVARIANT) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *idx* | The one-based index where to insert the item. |
| *dv* | The variant to insert. |

#### Return value

If the method succeeds, it returns TRUE; otherwise, FALSE.

---

## <a name="item2"></a>Item (DVarList)

Retrieves the item at the specified index.

```
FUNCTION Item (BYVAL idx AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *idx* | The one-based index of the item to retrieve. |

#### Return value

If the method succeeds, it returns TRUE; otherwise, FALSE.

---

## <a name="remove2"></a>Remove (DVarList)

Removes the specified item from the list. Indexes are one-based.

```
FUNCTION Remove (BYVAL idx AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *idx* | The one-based index of the item to remove. |

#### Return value

If the method succeeds, it returns TRUE; otherwise, FALSE.

---

## <a name="replace2"></a>Replace (DVarList)

Replaces the item at the specified index.

```
FUNCTION Replace (BYVAL idx AS LONG, BYREF dv AS DVARIANT) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *idx* | The one-based index of the item to replace. |
| *dv* | The replacement variant. |


#### Return value

If the method succeeds, it returns TRUE; otherwise, FALSE.

---
