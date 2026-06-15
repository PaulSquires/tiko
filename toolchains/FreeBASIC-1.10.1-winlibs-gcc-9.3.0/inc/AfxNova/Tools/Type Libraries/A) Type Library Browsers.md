# Type Library Browsers

Type libraries contain the binary description of one or more COM elements: classes, interfaces, enumerations, modules, constants, and more. They may exist as standalone .tlb files or be embedded as resources inside executables and libraries (.dll, .ocx, .exe).

To work with a COM object from a specific programming language, you must be able to inspect its type library in that language. Only then can you obtain the correct syntax for its classes, interfaces, methods, properties, and events.

Microsoft provides tools such as **OleView.exe** (included with Visual C++) and the **Object Browser** in Visual Basic 6. However, when working with `FreeBasic`, having a native browser makes it possible to explore COM libraries directly and generate code tailored to the language.

# Building a Type Library browser

Creating a type library browser involves reading and analyzing the binary metadata contained in .tlb, .dll, or .ocx files and converting it into a readable representation. This enables you to:

* Examine the internal structure of COM components
* Generate FreeBasic wrappers or declarations
* Understand the hierarchy of classes, interfaces, and modules
* Inspect constants, enumerations, and structures

Your browser relies on the fundamental COM system components:

* **LoadTypeLib** / **LoadTypeLibEx** to load the library
* **ITypeLib** to enumerate the available types
* **ITypeInfo** to retrieve detailed information for each type

The graphical interface is typically organized as a TreeView that reflects the hierarchy:

**TypeLib**<br>
 ├─ Documentation<br>
 ├─ GUIDs<br>
 ├─ Constants<br>
 ├─ Enumerations<br>
 ├─ Structures<br>
 ├─ Modules<br>
 ├─ CoClasses<br>
 └─ Interfaces<br>

#### Articles Containing the Code

The following sections explain, step by step, how to build a TypeLib Browser in FreeBasic. Each link points to a page containing the corresponding code:

* [Retrieving information from the registry](https://github.com/JoseRoca/AfxNova/blob/main/Tools/Type%20Libraries/B\)%20Retrieving%20the%20type%20libraries.md)
* [Loading the type library](https://github.com/JoseRoca/AfxNova/blob/main/Tools/Type%20Libraries/C\)%20Loading%20the%20type%20library.md)
* [Parsing the information](https://github.com/JoseRoca/AfxNova/blob/main/Tools/Type%20Libraries/D\)%20Parsing%20the%20information.md)
* [Enumerating the constants](https://github.com/JoseRoca/AfxNova/blob/main/Tools/Type%20Libraries/E\)%20Enumerating%20the%20constants.md)
* [Enumerating structures and constants](https://github.com/JoseRoca/AfxNova/blob/main/Tools/Type%20Libraries/F\)%20Enumerating%20structures%20and%20unions.md)
* [Aliases and typedefs](https://github.com/JoseRoca/AfxNova/blob/main/Tools/Type%20Libraries/G\)%20Aliases%20and%20typedefs.md)
* [Enumerations and modules](https://github.com/JoseRoca/AfxNova/blob/main/Tools/Type%20Libraries/H\)%20Enumerations%20and%20modules.md)
* [CoClasses](https://github.com/JoseRoca/AfxNova/blob/main/Tools/Type%20Libraries/I\)%20Retrieving%20the%20CoClasses.md)
* [Interfaces](https://github.com/JoseRoca/AfxNova/blob/main/Tools/Type%20Libraries/J\)%20Retireving%20the%20Interfaces.md)
* [Methods and properties](https://github.com/JoseRoca/AfxNova/blob/main/Tools/Type%20Libraries/K\)%20Retrieving%20methods%20and%20properties.md)
* [Parameters](https://github.com/JoseRoca/AfxNova/blob/main/Tools/Type%20Libraries/L\)%20Retrieving%20the%20parameters.md)

The sections above focus mainly on `FreeBasic` code examples that demonstrate how to load a type library, extract its metadata, and organize the information. For developers who want to explore or reuse the full implementation, can find the complete source here: https://github.com/JoseRoca/AfxNova/tree/main/Tools/TLB_101

### Step-by-step development

*  **Step 1: Load the Type Library**

Use the **LoadTypeLib** API function to load the `.tlb` file into memory. If the file is embedded within a DLL or EXE, use **LoadTypeLibEx** to extract it from the resource section.

* **Step 2: Enumerate type information**

Iterate through the **ITypeLib** interface to get the count of type descriptions. Use **GetTypeInfo** to retrieve each **ITypeInfo** interface. This provides access to the details of each class, interface, and enum.

* **Step 3: Parse the metadata**

For each **ITypeInfo**, extract the following:

**GUIDs**: The IID (Interface ID) and CLSID (Class ID).<br>
**CoClasses**: Component classes that can be instantiated.<br>
**Constants**: Fixed values that do not change during a program's execution.<br>
**Enumerations**: User-defined data types that consist of a set of named integer constants.<br>
**Structures:**: User-defined data types that group several related variables into one place.<br>
**Interfaces**: The methods, properties, and functions (VTable entries).<br>

* **Step 4: Display/Generate Output**

**View**: Map the parsed information into a TreeView.<br>
**Generate code**: Generate `FreeBasic` code with the corresponding declarations.
