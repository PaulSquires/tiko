'    tiko editor - Programmer's Code Editor for the FreeBASIC Compiler
'    Copyright (C) 2016-2025 Paul Squires, PlanetSquires Software
'
'    This program is free software: you can redistribute it and/or modify
'    it under the terms of the GNU General Public License as published by
'    the Free Software Foundation, either version 3 of the License, or
'    (at your option) any later version.
'
'    This program is distributed in the hope that it will be useful,
'    but WITHOUT any WARRANTY; without even the implied warranty of
'    MERCHANTABILITY or FITNESS for A PARTICULAR PURPOSE.  See the
'    GNU General Public License for more details.

#pragma once

declare function updateMRUFilesItems() as long
declare function updateMRUProjectFilesItems() as long
declare function OpenMRUFile( byval hwnd as HWND, byval wID as Long ) as long
declare function ClearMRUlist( byval wID as long ) as long
declare function UpdateMRUList( byref wzFilename as wstring ) as long
declare function OpenMRUProjectFile( byval hwnd as HWND, byval wID as long) as long
declare function UpdateMRUProjectList( byval wszFilename as CWSTR ) as long


