' ########################################################################################
' Platform: Microsoft Windows
' Filename: AfxD2D1Objects.bi
' Purpose:  D2D1 objects
' Compiler: FreeBASIC 32 & 64 bit
' Copyright (c) 2026 José Roca
'
' License: Distributed under the MIT license.
'
' Permission is hereby granted, free of charge, to any person obtaining a copy of this
' software and associated documentation files (the “Software”), to deal in the Software
' without restriction, including without limitation the rights to use, copy, modify, merge,
' publish, distribute, sublicense, and/or sell copies of the Software, and to permit
' persons to whom the Software is furnished to do so, subject to the following conditions:

' The above copyright notice and this permission notice shall be included in all copies or
' substantial portions of the Software.

' THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
' INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
' PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
' FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
' OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
' DEALINGS IN THE SOFTWARE.'
' ########################################################################################

#pragma once
#include once "AfxNova/AfxD2D1.bi"

' ========================================================================================
' Macro for debug
' To allow debugging, define _D2D1_DEBUG_ 1 in your application before including this file.
' ========================================================================================
#ifndef _D2D1_DEBUG_
   #define _D2D1_DEBUG_ 0
#ENDIF
#ifndef _D2D1_DP_
   #define _D2D1_DP_ 1
   #MACRO D2D1_DP(st)
      #IF (_D2D1_DEBUG_ = 1)
         OutputDebugStringW(__FUNCTION__ + ": " + st)
      #ENDIF
   #ENDMACRO
#ENDIF
' ========================================================================================

NAMESPACE AfxNova

' ########################################################################################
' CD2D1Factory class
' ########################################################################################

' ========================================================================================
TYPE CD2D1Factory
Public:

   m_pFactory AS ID2D1Factory PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory class. Default constructor.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory
   D2D1_DP("Default constructor - m_pFactory = " & WSTR(m_pFactory))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Creates an instance of the ID2D1Factory interface.
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory, BYVAL NULL, m_pFactory))
   D2D1_DP("m_pFactory - " & WSTR(m_pFactory))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory
   D2D1_DP("m_pFactory: " & WSTR(m_pFactory))
   IF m_pFactory THEN m_pFactory->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory) AS ID2D1Factory PTR
   RETURN factory.m_pFactory
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory.@ () AS ID2D1Factory PTR PTR
   RETURN @m_pFactory
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory.CAST () AS ID2D1Factory PTR
   RETURN m_pFactory
END OPERATOR
' ========================================================================================


' ########################################################################################
' CD2D1Factory1 class
' Creates Direct2D resources.
' ########################################################################################

' ========================================================================================
TYPE CD2D1Factory1 EXTENDS CD2D1Factory
Public:

   m_pFactory1 AS ID2D1Factory1 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory1 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory1 class. Default constructor.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory1
   D2D1_DP("Default constructor - m_pFactory1 = " & WSTR(m_pFactory1))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory1 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Creates an instance of the ID2D1Factory1 interface.
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory1, BYVAL NULL, m_pFactory1))
   D2D1_DP("m_pFactory1 - " & WSTR(m_pFactory1))
   ' // Increment the reference count
   IF m_pFactory1 THEN m_pFactory1->AddRef
   ' // Release the base factory if there is one
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END iF
   ' // Assign the new factory pointer to the base class
   m_pFactory = m_pFactory1
   D2D1_DP("Assign new factory: " & WSTR(m_pFactory))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory1
   D2D1_DP("m_pFactory1: " & WSTR(m_pFactory1))
   IF m_pFactory1 THEN m_pFactory1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory1 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory1) AS ID2D1Factory1 PTR
   RETURN factory.m_pFactory1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory1.@ () AS ID2D1Factory1 PTR PTR
   RETURN @m_pFactory1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory1.CAST () AS ID2D1Factory1 PTR
   RETURN m_pFactory1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory1.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory1)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CD2D1Factory2 class
' Creates Direct2D resources.
' ########################################################################################

' ========================================================================================
TYPE CD2D1Factory2 EXTENDS CD2D1Factory1
Public:

   m_pFactory2 AS ID2D1Factory2 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory2 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory2 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory2 class. Default constructor.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory2
   D2D1_DP("Default constructor - m_pFactory2 = " & WSTR(m_pFactory2))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory2 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory2 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Creates an instance of the ID2D1Factory2 interface.
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory2, BYVAL NULL, m_pFactory2))
   D2D1_DP("m_pFactory2 - " & WSTR(m_pFactory2))
   ' // Release the inherited factories
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END iF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END iF
   ' // Assign the new factory pointer to the inherited factories
   IF m_pFactory2 THEN m_pFactory2->AddRef
   m_pFactory1 = m_pFactory2
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))
   IF m_pFactory2 THEN m_pFactory2->AddRef
   m_pFactory = m_pFactory2
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory2
   D2D1_DP("m_pFactory2: " & WSTR(m_pFactory2))
   IF m_pFactory2 THEN m_pFactory2->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory2 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory2) AS ID2D1Factory2 PTR
   RETURN factory.m_pFactory2
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory2 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory2.@ () AS ID2D1Factory2 PTR PTR
   RETURN @m_pFactory2
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory2 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory2.CAST () AS ID2D1Factory2 PTR
   RETURN m_pFactory2
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory2.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory2)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CD2D1Factory3 class
' Creates Direct2D resources.
' ########################################################################################

' ========================================================================================
TYPE CD2D1Factory3 EXTENDS CD2D1Factory2
Public:

   m_pFactory3 AS ID2D1Factory3 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory3 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory3 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory3 class. Default constructor.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory3
   D2D1_DP("Default constructor - m_pFactory3 = " & WSTR(m_pFactory3))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory3 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory3 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Creates an instance of the ID2D1Factory2 interface.
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory3, BYVAL NULL, m_pFactory3))
   D2D1_DP("m_pFactory3 - " & WSTR(m_pFactory3))
   ' // Release the inherited factories
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END iF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END iF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END iF
   ' // Assign the new factory pointer to the inherited factories
   IF m_pFactory3 THEN m_pFactory3->AddRef
   m_pFactory2 = m_pFactory3
   D2D1_DP("Assign m_pFactory2: " & WSTR(m_pFactory2))
   IF m_pFactory3 THEN m_pFactory3->AddRef
   m_pFactory1 = m_pFactory3
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))
   IF m_pFactory3 THEN m_pFactory3->AddRef
   m_pFactory = m_pFactory3
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory3
   D2D1_DP("m_pFactory3: " & WSTR(m_pFactory3))
   IF m_pFactory3 THEN m_pFactory3->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory3 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory3) AS ID2D1Factory3 PTR
   RETURN factory.m_pFactory3
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory3 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory3.@ () AS ID2D1Factory3 PTR PTR
   RETURN @m_pFactory3
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory3 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory3.CAST () AS ID2D1Factory3 PTR
   RETURN m_pFactory3
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory3.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory3)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CD2D1Factory4 class
' Creates Direct2D resources.
' ########################################################################################

TYPE CD2D1Factory4 EXTENDS CD2D1Factory3
Public:

   m_pFactory4 AS ID2D1Factory4 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory4 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory4 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory4
   D2D1_DP("Default constructor - m_pFactory4 = " & WSTR(m_pFactory4))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory4 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory4 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Create ID2D1Factory4
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory4, BYVAL NULL, m_pFactory4))
   D2D1_DP("m_pFactory4 - " & WSTR(m_pFactory4))
   ' // Release inherited factories
   IF m_pFactory3 THEN
      m_pFactory3->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory3))
   END IF
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END IF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END IF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END IF

   ' // Assign the new factory pointer to all inherited pointers
   IF m_pFactory4 THEN m_pFactory4->AddRef
   m_pFactory3 = m_pFactory4
   D2D1_DP("Assign m_pFactory3: " & WSTR(m_pFactory3))

   IF m_pFactory4 THEN m_pFactory4->AddRef
   m_pFactory2 = m_pFactory4
   D2D1_DP("Assign m_pFactory2: " & WSTR(m_pFactory2))

   IF m_pFactory4 THEN m_pFactory4->AddRef
   m_pFactory1 = m_pFactory4
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))

   IF m_pFactory4 THEN m_pFactory4->AddRef
   m_pFactory = m_pFactory4
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))

END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory4
   D2D1_DP("m_pFactory4: " & WSTR(m_pFactory4))
   IF m_pFactory4 THEN m_pFactory4->Release
END DESTRUCTOR
' =================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory4 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory4) AS ID2D1Factory4 PTR
   RETURN factory.m_pFactory4
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory4 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory4.@ () AS ID2D1Factory4 PTR PTR
   RETURN @m_pFactory4
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory4 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory4.CAST () AS ID2D1Factory4 PTR
   RETURN m_pFactory4
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory4.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory4)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CD2D1Factory5 class
' Creates Direct2D resources.
' ########################################################################################

TYPE CD2D1Factory5 EXTENDS CD2D1Factory4
Public:

   m_pFactory5 AS ID2D1Factory5 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory5 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory5 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory5
   D2D1_DP("Default constructor - m_pFactory5 = " & WSTR(m_pFactory5))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory5 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory5 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Create ID2D1Factory5
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory5, BYVAL NULL, m_pFactory5))
   D2D1_DP("m_pFactory5 - " & WSTR(m_pFactory5))
   ' // Release inherited factories
   IF m_pFactory4 THEN
      m_pFactory4->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory4))
   END IF
   IF m_pFactory3 THEN
      m_pFactory3->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory3))
   END IF
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END IF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END IF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END IF

   ' // Assign the new factory pointer to all inherited pointers
   IF m_pFactory5 THEN m_pFactory5->AddRef
   m_pFactory4 = m_pFactory5
   D2D1_DP("Assign m_pFactory4: " & WSTR(m_pFactory4))

   IF m_pFactory5 THEN m_pFactory5->AddRef
   m_pFactory3 = m_pFactory5
   D2D1_DP("Assign m_pFactory3: " & WSTR(m_pFactory3))

   IF m_pFactory5 THEN m_pFactory5->AddRef
   m_pFactory2 = m_pFactory5
   D2D1_DP("Assign m_pFactory2: " & WSTR(m_pFactory2))

   IF m_pFactory5 THEN m_pFactory5->AddRef
   m_pFactory1 = m_pFactory5
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))

   IF m_pFactory5 THEN m_pFactory5->AddRef
   m_pFactory = m_pFactory5
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))

END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory5
   D2D1_DP("m_pFactory5: " & WSTR(m_pFactory5))
   IF m_pFactory5 THEN m_pFactory5->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory5 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory5) AS ID2D1Factory5 PTR
   RETURN factory.m_pFactory5
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory5 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory5.@ () AS ID2D1Factory5 PTR PTR
   RETURN @m_pFactory5
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory5 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory5.CAST () AS ID2D1Factory5 PTR
   RETURN m_pFactory5
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory5.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory5)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CD2D1Factory6 class
' Creates Direct2D resources.
' ########################################################################################

TYPE CD2D1Factory6 EXTENDS CD2D1Factory5
Public:

   m_pFactory6 AS ID2D1Factory6 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory6 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory6 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory6
   D2D1_DP("Default constructor - m_pFactory6 = " & WSTR(m_pFactory6))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory6 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory6 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Create ID2D1Factory6
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory6, BYVAL NULL, m_pFactory6))
   D2D1_DP("m_pFactory6 - " & WSTR(m_pFactory6))
   ' // Release inherited factories
   IF m_pFactory5 THEN
      m_pFactory5->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory5))
   END IF
   IF m_pFactory4 THEN
      m_pFactory4->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory4))
   END IF
   IF m_pFactory3 THEN
      m_pFactory3->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory3))
   END IF
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END IF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END IF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END IF

   ' // Assign the new factory pointer to all inherited pointers
   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory5 = m_pFactory6
   D2D1_DP("Assign m_pFactory5: " & WSTR(m_pFactory5))

   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory4 = m_pFactory6
   D2D1_DP("Assign m_pFactory4: " & WSTR(m_pFactory4))

   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory3 = m_pFactory6
   D2D1_DP("Assign m_pFactory3: " & WSTR(m_pFactory3))

   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory2 = m_pFactory6
   D2D1_DP("Assign m_pFactory2: " & WSTR(m_pFactory2))

   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory1 = m_pFactory6
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))

   IF m_pFactory6 THEN m_pFactory6->AddRef
   m_pFactory = m_pFactory6
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))

END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory6
   D2D1_DP("m_pFactory6: " & WSTR(m_pFactory6))
   IF m_pFactory6 THEN m_pFactory6->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory6 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory6) AS ID2D1Factory6 PTR
   RETURN factory.m_pFactory6
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory6 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory6.@ () AS ID2D1Factory6 PTR PTR
   RETURN @m_pFactory6
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory6 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory6.CAST () AS ID2D1Factory6 PTR
   RETURN m_pFactory6
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory6.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory6)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CD2D1Factory7 class
' Creates Direct2D resources.
' ########################################################################################

TYPE CD2D1Factory7 EXTENDS CD2D1Factory6
Public:

   m_pFactory7 AS ID2D1Factory7 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory7 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory7 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory7
   D2D1_DP("Default constructor - m_pFactory7 = " & WSTR(m_pFactory7))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory7 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory7 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Create ID2D1Factory7
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory7, BYVAL NULL, m_pFactory7))
   D2D1_DP("m_pFactory7 - " & WSTR(m_pFactory7))
   ' // Release inherited factories
   IF m_pFactory6 THEN
      m_pFactory6->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory6))
   END IF
   IF m_pFactory5 THEN
      m_pFactory5->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory5))
   END IF
   IF m_pFactory4 THEN
      m_pFactory4->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory4))
   END IF
   IF m_pFactory3 THEN
      m_pFactory3->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory3))
   END IF
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END IF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END IF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END IF

   ' // Assign the new factory pointer to all inherited pointers
   IF m_pFactory7 THEN m_pFactory7->AddRef
   m_pFactory6 = m_pFactory7
   D2D1_DP("Assign m_pFactory6: " & WSTR(m_pFactory6))

   IF m_pFactory7 THEN m_pFactory7->AddRef
   m_pFactory = m_pFactory7
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))

END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory7
   D2D1_DP("m_pFactory7: " & WSTR(m_pFactory7))
   IF m_pFactory7 THEN m_pFactory7->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory7 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory7) AS ID2D1Factory7 PTR
   RETURN factory.m_pFactory7
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory7 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory7.@ () AS ID2D1Factory7 PTR PTR
   RETURN @m_pFactory7
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory7 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory7.CAST () AS ID2D1Factory7 PTR
   RETURN m_pFactory7
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory7.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory7)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CD2D1Factory8 class
' Creates Direct2D resources.
' Not yet implemented.
' ########################################################################################

TYPE CD2D1Factory8 EXTENDS CD2D1Factory7
Public:

   m_pFactory8 AS ID2D1Factory8 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Factory8 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory8 PTR
   DECLARE OPERATOR CAST () AS ID2D1Factory PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory8
   D2D1_DP("Default constructor - m_pFactory8 = " & WSTR(m_pFactory8))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CD2D1Factory8 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CD2D1Factory8 (BYVAL factoryType AS D2D1_FACTORY_TYPE)
   ' // Create ID2D1Factory8
   SetLastError(D2D1CreateFactory(factoryType, IID_ID2D1Factory8, BYVAL NULL, m_pFactory8))
   D2D1_DP("m_pFactory8 - " & WSTR(m_pFactory8))
   ' // Release inherited factories
   IF m_pFactory7 THEN
      m_pFactory7->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory7))
   END IF
   IF m_pFactory6 THEN
      m_pFactory6->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory6))
   END IF
   IF m_pFactory5 THEN
      m_pFactory5->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory5))
   END IF
   IF m_pFactory4 THEN
      m_pFactory4->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory4))
   END IF
   IF m_pFactory3 THEN
      m_pFactory3->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory3))
   END IF
   IF m_pFactory2 THEN
      m_pFactory2->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory2))
   END IF
   IF m_pFactory1 THEN
      m_pFactory1->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory1))
   END IF
   IF m_pFactory THEN
      m_pFactory->Release
      D2D1_DP("Release old factory: " & WSTR(m_pFactory))
   END IF

   ' // Assign the new factory pointer to all inherited pointers
   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory7 = m_pFactory8
   D2D1_DP("Assign m_pFactory7: " & WSTR(m_pFactory7))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory6 = m_pFactory8
   D2D1_DP("Assign m_pFactory6: " & WSTR(m_pFactory6))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory5 = m_pFactory8
   D2D1_DP("Assign m_pFactory5: " & WSTR(m_pFactory5))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory4 = m_pFactory8
   D2D1_DP("Assign m_pFactory4: " & WSTR(m_pFactory4))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory3 = m_pFactory8
   D2D1_DP("Assign m_pFactory3: " & WSTR(m_pFactory3))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory2 = m_pFactory8
   D2D1_DP("Assign m_pFactory2: " & WSTR(m_pFactory2))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory1 = m_pFactory8
   D2D1_DP("Assign m_pFactory1: " & WSTR(m_pFactory1))

   IF m_pFactory8 THEN m_pFactory8->AddRef
   m_pFactory = m_pFactory8
   D2D1_DP("Assign m_pFactory: " & WSTR(m_pFactory))

END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CD2D1Factory8
   D2D1_DP("m_pFactory8: " & WSTR(m_pFactory8))
   IF m_pFactory8 THEN m_pFactory8->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Factory8 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF factory AS CD2D1Factory8) AS ID2D1Factory8 PTR
   RETURN factory.m_pFactory8
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Factory8  interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory8 .@ () AS ID2D1Factory8  PTR PTR
   RETURN @m_pFactory8
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory8 interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory8.CAST () AS ID2D1Factory8 PTR
   RETURN m_pFactory8
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Factory interface pointer
' ========================================================================================
PRIVATE OPERATOR CD2D1Factory8.CAST () AS ID2D1Factory PTR
   RETURN cast(ID2D1Factory PTR, m_pFactory8)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1RenderTarget class
' ########################################################################################

' ========================================================================================
TYPE CID2D1RenderTarget
Public:

   m_pRenderTarget AS ID2D1RenderTarget PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pRenderTarget AS ID2D1RenderTarget PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1RenderTarget PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1RenderTarget PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1RenderTarget class.
' ========================================================================================
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RenderTarget
   D2D1_DP("Default")
END CONSTRUCTOR
' ========================================================================================
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RenderTarget (BYVAL pRenderTarget AS ID2D1RenderTarget PTR)
   D2D1_DP("pRenderTarget - " & WSTR(pRenderTarget))
   m_pRenderTarget = pRenderTarget
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1RenderTarget
   D2D1_DP("m_pRenderTarget: " & WSTR(m_pRenderTarget))
   IF m_pRenderTarget THEN m_pRenderTarget->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1RenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF renderTarget AS CID2D1RenderTarget) AS ID2D1RenderTarget PTR
   RETURN renderTarget.m_pRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1RenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RenderTarget.@ () AS ID2D1RenderTarget PTR PTR
   RETURN @m_pRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1RenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RenderTarget.CAST () AS ID2D1RenderTarget PTR
   RETURN m_pRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RenderTarget.CAST () AS ID2D1Resource PTR
   RETURN CAST(ID2D1Resource PTR, m_pRenderTarget)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1DCRenderTarget class
' ########################################################################################

' ========================================================================================
TYPE CID2D1DCRenderTarget EXTENDS CID2D1RenderTarget
Public:

   m_pDCRenderTarget AS ID2D1DCRenderTarget PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pDCRenderTarget AS ID2D1DCRenderTarget PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1DCRenderTarget PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1DCRenderTarget PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1DCRenderTarget class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1DCRenderTarget
   D2D1_DP(" - default")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1DCRenderTarget class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1DCRenderTarget (BYVAL pDCRenderTarget AS ID2D1DCRenderTarget PTR)
   D2D1_DP("pDCRenderTarget - " & WSTR(pDCRenderTarget))
   m_pDCRenderTarget = pDCRenderTarget
   IF m_pDCRenderTarget THEN m_pDCRenderTarget->AddRef
   m_pRenderTarget = CAST(ID2D1RenderTarget PTR, m_pDCRenderTarget)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1DCRenderTarget
   D2D1_DP("m_pDCRenderTarget: " & WSTR(m_pDCRenderTarget))
   IF m_pDCRenderTarget THEN m_pDCRenderTarget->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1DCRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF renderTarget AS CID2D1DCRenderTarget) AS ID2D1DCRenderTarget PTR
   RETURN renderTarget.m_pDCRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1DCRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1DCRenderTarget.@ () AS ID2D1DCRenderTarget PTR PTR
   RETURN @m_pDCRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1DCRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1DCRenderTarget.CAST () AS ID2D1DCRenderTarget PTR
   RETURN m_pDCRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1DCRenderTarget.CAST () AS ID2D1Resource PTR
   RETURN CAST(ID2D1Resource PTR, m_pDCRenderTarget)
END OPERATOR
' ========================================================================================

' ########################################################################################
' CID2D1HwndRenderTarget class
' Renders drawing instructions to a window.
' ########################################################################################

' ========================================================================================
TYPE CID2D1HwndRenderTarget EXTENDS CID2D1RenderTarget
Public:

   m_pHwndRenderTarget AS ID2D1HwndRenderTarget PTR

   DECLARE CONSTRUCTOR (BYVAL pHwndRenderTarget AS ID2D1HwndRenderTarget PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1HwndRenderTarget PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1HwndRenderTarget PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1HwndRenderTarget class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1HwndRenderTarget (BYVAL pHwndRenderTarget AS ID2D1HwndRenderTarget PTR)
   D2D1_DP("HwndRenderTarget - " & WSTR(pHwndRenderTarget))
   m_pHwndRenderTarget = pHwndRenderTarget
   IF m_pHwndRenderTarget THEN m_pHwndRenderTarget->AddRef
   m_pRenderTarget = CAST(ID2D1RenderTarget PTR, m_pHwndRenderTarget)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1HwndRenderTarget
   D2D1_DP("m_pHwndRenderTarget: " & WSTR(m_pHwndRenderTarget))
   IF m_pHwndRenderTarget THEN m_pHwndRenderTarget->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1HwndRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF renderTarget AS CID2D1HwndRenderTarget) AS ID2D1HwndRenderTarget PTR
   RETURN renderTarget.m_pHwndRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1HwndRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1HwndRenderTarget.@ () AS ID2D1HwndRenderTarget PTR PTR
   RETURN @m_pHwndRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1HwndRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1HwndRenderTarget.CAST () AS ID2D1HwndRenderTarget PTR
   RETURN m_pHwndRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1HwndRenderTarget.CAST () AS ID2D1Resource PTR
   RETURN CAST(ID2D1Resource PTR, m_pHwndRenderTarget)
END OPERATOR
' ========================================================================================

' ########################################################################################
' CID2D1BitmapRenderTarget class
' Renders to an intermediate texture created by the CreateCompatibleRenderTarget method.
' ########################################################################################

' ========================================================================================
TYPE CID2D1BitmapRenderTarget EXTENDS CID2D1RenderTarget
Public:

   m_pBitmapRenderTarget AS ID2D1BitmapRenderTarget PTR

   DECLARE CONSTRUCTOR (BYVAL pBitmapRenderTarget AS ID2D1BitmapRenderTarget PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1BitmapRenderTarget PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1BitmapRenderTarget PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1HwndRenderTarget class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1BitmapRenderTarget (BYVAL pBitmapRenderTarget AS ID2D1BitmapRenderTarget PTR)
   D2D1_DP("BitmapRenderTarget - " & WSTR(pBitmapRenderTarget))
   m_pBitmapRenderTarget = pBitmapRenderTarget
   IF m_pBitmapRenderTarget THEN m_pBitmapRenderTarget->AddRef
   m_pRenderTarget = CAST(ID2D1RenderTarget PTR, m_pBitmapRenderTarget)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1BitmapRenderTarget
   D2D1_DP("m_pBitmapRenderTarget: " & WSTR(m_pBitmapRenderTarget))
   IF m_pBitmapRenderTarget THEN m_pBitmapRenderTarget->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1BitmapRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF renderTarget AS CID2D1BitmapRenderTarget) AS ID2D1BitmapRenderTarget PTR
   RETURN renderTarget.m_pBitmapRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1BitmapRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapRenderTarget.@ () AS ID2D1BitmapRenderTarget PTR PTR
   RETURN @m_pBitmapRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1BitmapRenderTarget interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapRenderTarget.CAST () AS ID2D1BitmapRenderTarget PTR
   RETURN m_pBitmapRenderTarget
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapRenderTarget.CAST () AS ID2D1Resource PTR
   RETURN CAST(ID2D1Resource PTR, m_pBitmapRenderTarget)
END OPERATOR
' ========================================================================================

' ########################################################################################
' CID2D1GradientStopCollection class
' Represents a collection of D2D1_GRADIENT_STOP objects for linear and radial gradient brushes.
' ########################################################################################

TYPE CID2D1GradientStopCollection
Public:

   m_pGradientStopCollection AS ID2D1GradientStopCollection PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pGradientStopCollection AS ID2D1GradientStopCollection PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1GradientStopCollection PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1GradientStopCollection PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GradientStopCollection class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GradientStopCollection
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GradientStopCollection class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GradientStopCollection (BYVAL pGradientStopCollection AS ID2D1GradientStopCollection PTR)
   D2D1_DP("pGradientStopCollection - " & WSTR(pGradientStopCollection))
   m_pGradientStopCollection = pGradientStopCollection
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1GradientStopCollection
   D2D1_DP("m_pGradientStopCollection: " & WSTR(m_pGradientStopCollection))
   IF m_pGradientStopCollection THEN m_pGradientStopCollection->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF gradientStopCollection AS CID2D1GradientStopCollection) AS ID2D1GradientStopCollection PTR
   RETURN gradientStopCollection.m_pGradientStopCollection
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GradientStopCollection.@ () AS ID2D1GradientStopCollection PTR PTR
   RETURN @m_pGradientStopCollection
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GradientStopCollection.CAST () AS ID2D1GradientStopCollection PTR
   RETURN m_pGradientStopCollection
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GradientStopCollection.CAST () AS ID2D1Resource PTR
   RETURN CAST(ID2D1Resource PTR, m_pGradientStopCollection)
END OPERATOR
' ========================================================================================

' ########################################################################################
' CID2D1GradientStopCollection1 class
' Represents a collection of D2D1_GRADIENT_STOP objects for linear and radial gradient brushes.
' It provides get methods for all the new parameters added to the gradient stop collection.
' ########################################################################################

TYPE CID2D1GradientStopCollection1 EXTENDS CID2D1GradientStopCollection
Public:

   m_pGradientStopCollection1 AS ID2D1GradientStopCollection1 PTR

   DECLARE CONSTRUCTOR (BYVAL pGradientStopCollection1 AS ID2D1GradientStopCollection1 PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1GradientStopCollection1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1GradientStopCollection1 PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GradientStopCollection class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GradientStopCollection1 (BYVAL pGradientStopCollection1 AS ID2D1GradientStopCollection1 PTR)
   D2D1_DP("pGradientStopCollection1 - " & WSTR(pGradientStopCollection1))
   m_pGradientStopCollection1 = pGradientStopCollection1
   IF m_pGradientStopCollection1 THEN m_pGradientStopCollection1->AddRef
   m_pGradientStopCollection = m_pGradientStopCollection1
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1GradientStopCollection1
   D2D1_DP("m_pGradientStopCollection1: " & WSTR(1))
   IF m_pGradientStopCollection1 THEN m_pGradientStopCollection1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF gradientStopCollection AS CID2D1GradientStopCollection1) AS ID2D1GradientStopCollection1 PTR
   RETURN gradientStopCollection.m_pGradientStopCollection1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GradientStopCollection1.@ () AS ID2D1GradientStopCollection1 PTR PTR
   RETURN @m_pGradientStopCollection1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1GradientStopCollection interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GradientStopCollection1.CAST () AS ID2D1GradientStopCollection1 PTR
   RETURN m_pGradientStopCollection1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GradientStopCollection1.CAST () AS ID2D1Resource PTR
   RETURN CAST(ID2D1Resource PTR, m_pGradientStopCollection)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1SolidColorBrush class
' Paints an area with a solid color.
' ########################################################################################

' ========================================================================================
TYPE CID2D1SolidColorBrush
Public:

   m_pSolidColorBrush AS ID2D1SolidColorBrush PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pSolidColorBrush AS ID2D1SolidColorBrush PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1SolidColorBrush PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1SolidColorBrush PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1SolidColorBrush class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1SolidColorBrush
   D2D1_DP(" - default")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1SolidColorBrush class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1SolidColorBrush (BYVAL pSolidColorBrush AS ID2D1SolidColorBrush PTR)
   D2D1_DP("pSolidColorBrush - " & WSTR(pSolidColorBrush))
   m_pSolidColorBrush = psolidColorBrush
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1SolidColorBrush
   D2D1_DP("m_pSolidColorBrush: " & WSTR(m_pSolidColorBrush))
   IF m_pSolidColorBrush THEN m_pSolidColorBrush->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1SolidColorBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF solidColorBrush AS CID2D1SolidColorBrush) AS ID2D1SolidColorBrush PTR
   RETURN solidColorBrush.m_pSolidColorBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1SolidColorBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1SolidColorBrush.@ () AS ID2D1SolidColorBrush PTR PTR
   RETURN @m_pSolidColorBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1SolidColorBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1SolidColorBrush.CAST () AS ID2D1SolidColorBrush PTR
   RETURN m_pSolidColorBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1SolidColorBrush.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pSolidColorBrush)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1SolidColorBrush.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pSolidColorBrush)
END OPERATOR
' ========================================================================================

' ########################################################################################
' CID2D1LinearGradientBrush class
' Paints an area with a linear gradient.
' ########################################################################################

' ========================================================================================
TYPE CID2D1LinearGradientBrush
Public:

   m_pLinearGradientBrush AS ID2D1LinearGradientBrush PTR

   DECLARE CONSTRUCTOR (BYVAL pLinearGradientBrush AS ID2D1LinearGradientBrush PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1LinearGradientBrush PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1LinearGradientBrush PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1LinearGraientBrush class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1LinearGradientBrush (BYVAL pLinearGradientBrush AS ID2D1LinearGradientBrush PTR)
   D2D1_DP("pLinearGradientBrush - " & WSTR(pLinearGradientBrush))
   m_pLinearGradientBrush = pLinearGradientBrush
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1LinearGradientBrush
   D2D1_DP("m_pLinearGradientBrush: " & WSTR(m_pLinearGradientBrush))
   IF m_pLinearGradientBrush THEN m_pLinearGradientBrush->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF linearGradientBrush AS CID2D1LinearGradientBrush) AS ID2D1LinearGradientBrush PTR
   RETURN linearGradientBrush.m_pLinearGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1LinearGradientBrush.@ () AS ID2D1LinearGradientBrush PTR PTR
   RETURN @m_pLinearGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1LinearGradientBrush.CAST () AS ID2D1LinearGradientBrush PTR
   RETURN m_pLinearGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1LinearGradientBrush.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pLinearGradientBrush)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1LinearGradientBrush.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pLinearGradientBrush)
END OPERATOR
' ========================================================================================

' ########################################################################################
' CID2D1RadialGradientBrush class
' Paints an area with a radial gradient.
' ########################################################################################

' ========================================================================================
TYPE CID2D1RadialGradientBrush
Public:

   m_pRadialGradientBrush AS ID2D1RadialGradientBrush PTR

   DECLARE CONSTRUCTOR (BYVAL pRadialGradientBrush AS ID2D1RadialGradientBrush PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1RadialGradientBrush PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1RadialGradientBrush PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1RadialGradientBrush class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RadialGradientBrush (BYVAL pRadialGradientBrush AS ID2D1RadialGradientBrush PTR)
   D2D1_DP("pRadialGradientBrush - " & WSTR(pRadialGradientBrush))
   m_pRadialGradientBrush = pRadialGradientBrush
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1RadialGradientBrush
   D2D1_DP("m_pRadialGradientBrush: " & WSTR(m_pRadialGradientBrush))
   IF m_pRadialGradientBrush THEN m_pRadialGradientBrush->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF radialGradientBrush AS CID2D1RadialGradientBrush) AS ID2D1RadialGradientBrush PTR
   RETURN radialGradientBrush.m_pRadialGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RadialGradientBrush.@ () AS ID2D1RadialGradientBrush PTR PTR
   RETURN @m_pRadialGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1LinearGradientBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RadialGradientBrush.CAST () AS ID2D1RadialGradientBrush PTR
   RETURN m_pRadialGradientBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RadialGradientBrush.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pRadialGradientBrush)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RadialGradientBrush.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pRadialGradientBrush)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1BitmapBrush class
' Paints an area with a bitmap.
' ########################################################################################

' ========================================================================================
TYPE CID2D1BitmapBrush
Public:

   m_pBitmapBrush AS ID2D1BitmapBrush PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pID2D1BitmapBrush AS ID2D1BitmapBrush PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1BitmapBrush PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1BitmapBrush PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1BitmapBrush
   D2D1_DP("Default")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1BitmapBrush class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1BitmapBrush (BYVAL pBitmapBrush AS ID2D1BitmapBrush PTR)
   D2D1_DP("pBitmapBrush - " & WSTR(pBitmapBrush))
   m_pBitmapBrush = pBitmapBrush
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1BitmapBrush
   D2D1_DP("m_pBitmapBrush: " & WSTR(m_pBitmapBrush))
   IF m_pBitmapBrush THEN m_pBitmapBrush->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1BitmapBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF bitmapBrush AS CID2D1BitmapBrush) AS ID2D1BitmapBrush PTR
   RETURN bitmapBrush.m_pBitmapBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1BitmapBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush.@ () AS ID2D1BitmapBrush PTR PTR
   RETURN @m_pBitmapBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1BitmapBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush.CAST () AS ID2D1BitmapBrush PTR
   RETURN m_pBitmapBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pBitmapBrush)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pBitmapBrush)
END OPERATOR
' ========================================================================================

' ########################################################################################
' CID2D1BitmapBrush1 class
' Paints an area with a bitmap.
' ########################################################################################

' ========================================================================================
TYPE CID2D1BitmapBrush1 EXTENDS CID2D1BitmapBrush
Public:

   m_pBitmapBrush1 AS ID2D1BitmapBrush1 PTR

   DECLARE CONSTRUCTOR (BYVAL pBitmapBrush1 AS ID2D1BitmapBrush1 PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1BitmapBrush1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1BitmapBrush1 PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1BitmapBrush1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1BitmapBrush1 (BYVAL pBitmapBrush1 AS ID2D1BitmapBrush1 PTR)
   D2D1_DP("pBitmapBrush - " & WSTR(pBitmapBrush1))
   m_pBitmapBrush1 = pBitmapBrush1
   IF m_pBitmapBrush1 THEN m_pBitmapBrush1->AddRef
   m_pBitmapBrush = CAST(ID2D1BitmapBrush PTR, m_pBitmapBrush1)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1BitmapBrush1
   D2D1_DP("m_pBitmapBrush1: " & WSTR(m_pBitmapBrush1))
   IF m_pBitmapBrush1 THEN m_pBitmapBrush1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying CID2D1BitmapBrush1 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF bitmapBrush AS CID2D1BitmapBrush1) AS ID2D1BitmapBrush1 PTR
   RETURN bitmapBrush.m_pBitmapBrush1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying CID2D1BitmapBrush1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush1.@ () AS ID2D1BitmapBrush1 PTR PTR
   RETURN @m_pBitmapBrush1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1BitmapBrush1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush1.CAST () AS ID2D1BitmapBrush1 PTR
   RETURN m_pBitmapBrush1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush1.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pBitmapBrush1)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1BitmapBrush1.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pBitmapBrush1)
END OPERATOR
' ========================================================================================

' ########################################################################################
' CID2D1ImageBrush class
' Represents a brush based on an ID2D1Image.
' ########################################################################################

' ========================================================================================
TYPE CID2D1ImageBrush
Public:

   m_pImageBrush AS ID2D1ImageBrush PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pID2D1ImageBrush AS ID2D1ImageBrush PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1ImageBrush PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1ImageBrush PTR
   DECLARE OPERATOR CAST () AS ID2D1Brush PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1ImageBrush class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1ImageBrush (BYVAL pImageBrush AS ID2D1ImageBrush PTR)
   D2D1_DP("pImageBrush - " & WSTR(pImageBrush))
   m_pImageBrush = pImageBrush
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1ImageBrush
   D2D1_DP("m_pImageBrush: " & WSTR(m_pImageBrush))
   IF m_pImageBrush THEN m_pImageBrush->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1ImageBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF imageBrush AS CID2D1ImageBrush) AS ID2D1ImageBrush PTR
   RETURN imageBrush.m_pImageBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1ImageBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1ImageBrush.@ () AS ID2D1ImageBrush PTR PTR
   RETURN @m_pImageBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1ImageBrush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1ImageBrush.CAST () AS ID2D1ImageBrush PTR
   RETURN m_pImageBrush
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Brush interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1ImageBrush.CAST () AS ID2D1Brush PTR
   RETURN cast(ID2D1Brush PTR, m_pImageBrush)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1ImageBrush.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pImageBrush)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1Geometry class
' Represents a geometry resource and defines a set of helper methods for manipulating and
' measuring geometric shapes. 
' ########################################################################################

TYPE CID2D1Geometry
Public:

   m_pGeometry AS ID2D1Geometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pGeometry AS ID2D1Geometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1Geometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1Geometry PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Geometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1Geometry
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Geometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1Geometry (BYVAL pGeometry AS ID2D1Geometry PTR)
   D2D1_DP("pGeometry - " & WSTR(pGeometry))
   m_pGeometry = pGeometry
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1Geometry
   D2D1_DP("m_pGeometry: " & WSTR(m_pGeometry))
   IF m_pGeometry THEN m_pGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1Geometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1Geometry) AS ID2D1Geometry PTR
   RETURN geometry.m_pGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1Geometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1Geometry.@ () AS ID2D1Geometry PTR PTR
   RETURN @m_pGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Geometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1Geometry.CAST () AS ID2D1Geometry PTR
   RETURN m_pGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1Geometry.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pGeometry)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1RectangleGeometry class
' Describes a two-dimensional rectangle.
' ########################################################################################

' ========================================================================================
TYPE CID2D1RectangleGeometry EXTENDS CID2D1Geometry
Public:

   m_pRectangleGeometry AS ID2D1RectangleGeometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pRectangleGeometry AS ID2D1RectangleGeometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1RectangleGeometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1RectangleGeometry PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1RectangleGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RectangleGeometry
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1Geometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RectangleGeometry (BYVAL pRectangleGeometry AS ID2D1RectangleGeometry PTR)
   D2D1_DP("pRectangleGeometry - " & WSTR(pRectangleGeometry))
   m_pRectangleGeometry = pRectangleGeometry
   IF m_pRectangleGeometry THEN m_pRectangleGeometry->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pRectangleGeometry
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1RectangleGeometry
   D2D1_DP("m_pRectangleGeometry: " & WSTR(m_pRectangleGeometry))
   IF m_pRectangleGeometry THEN m_pRectangleGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1RectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1RectangleGeometry) AS ID2D1RectangleGeometry PTR
   RETURN geometry.m_pRectangleGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1RectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RectangleGeometry.@ () AS ID2D1RectangleGeometry PTR PTR
   RETURN @m_pRectangleGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1RectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RectangleGeometry.CAST () AS ID2D1RectangleGeometry PTR
   RETURN m_pRectangleGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RectangleGeometry.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pRectangleGeometry)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1RoundedRectangleGeometry class
' Describes a rounded rectangle.
' ########################################################################################

' ========================================================================================
TYPE CID2D1RoundedRectangleGeometry EXTENDS CID2D1Geometry
Public:

   m_pRoundedRectangleGeometry AS ID2D1RoundedRectangleGeometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pRectangleGeometry AS ID2D1RoundedRectangleGeometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1RoundedRectangleGeometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1RoundedRectangleGeometry PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1RoundedRectangleGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RoundedRectangleGeometry
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1RoundedRectangleGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1RoundedRectangleGeometry (BYVAL pRoundedRectangleGeometry AS ID2D1RoundedRectangleGeometry PTR)
   D2D1_DP("pRoundedRectangleGeometry - " & WSTR(pRoundedRectangleGeometry))
   m_pRoundedRectangleGeometry = pRoundedRectangleGeometry
   IF m_pRoundedRectangleGeometry THEN m_pRoundedRectangleGeometry->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pRoundedRectangleGeometry
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1RoundedRectangleGeometry
   D2D1_DP("m_pRoundedRectangleGeometry: " & WSTR(m_pRoundedRectangleGeometry))
   IF m_pRoundedRectangleGeometry THEN m_pRoundedRectangleGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1RoundedRectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1RoundedRectangleGeometry) AS ID2D1RoundedRectangleGeometry PTR
   RETURN geometry.m_pRoundedRectangleGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1RoundedRectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RoundedRectangleGeometry.@ () AS ID2D1RoundedRectangleGeometry PTR PTR
   RETURN @m_pRoundedRectangleGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1RectangleGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RoundedRectangleGeometry.CAST () AS ID2D1RoundedRectangleGeometry PTR
   RETURN m_pRoundedRectangleGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1RoundedRectangleGeometry.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pRoundedRectangleGeometry)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1EllipseGeometry class
' Represents an ellipse.
' ########################################################################################

' ========================================================================================
TYPE CID2D1EllipseGeometry EXTENDS CID2D1Geometry
Public:

   m_pEllipseGeometry AS ID2D1EllipseGeometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pEllipseGeometry AS ID2D1EllipseGeometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1EllipseGeometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1EllipseGeometry PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1EllipseGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1EllipseGeometry
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1EllipseGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1EllipseGeometry (BYVAL pEllipseGeometry AS ID2D1EllipseGeometry PTR)
   D2D1_DP("pEllipseGeometry - " & WSTR(pEllipseGeometry))
   m_pEllipseGeometry = pEllipseGeometry
   IF m_pEllipseGeometry THEN m_pEllipseGeometry->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pEllipseGeometry
   IF m_pEllipseGeometry = NULL THEN SetLastError(E_POINTER)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1EllipseGeometry
   D2D1_DP("m_pEllipseGeometry: " & WSTR(m_pEllipseGeometry))
   IF m_pEllipseGeometry THEN m_pEllipseGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1EllipseGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1EllipseGeometry) AS ID2D1EllipseGeometry PTR
   RETURN geometry.m_pEllipseGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1EllipseGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1EllipseGeometry.@ () AS ID2D1EllipseGeometry PTR PTR
   RETURN @m_pEllipseGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1EllipseGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1EllipseGeometry.CAST () AS ID2D1EllipseGeometry PTR
   RETURN m_pEllipseGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1EllipseGeometry.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pEllipseGeometry)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1GeometryGroup class
' Represents a composite geometry, composed of other ID2D1Geometry objects.
' ########################################################################################

' ========================================================================================
TYPE CID2D1GeometryGroup EXTENDS CID2D1Geometry
Public:

   m_pGeometryGroup AS ID2D1GeometryGroup PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pEllipseGeometry AS ID2D1GeometryGroup PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1GeometryGroup PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1GeometryGroup PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GeometryGroup class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GeometryGroup
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GeometryGroup class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GeometryGroup (BYVAL pGeometryGroup AS ID2D1GeometryGroup PTR)
   D2D1_DP("pGeometryGroup - " & WSTR(pGeometryGroup))
   m_pGeometryGroup = pGeometryGroup
   IF m_pGeometryGroup THEN m_pGeometryGroup->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pGeometryGroup
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1GeometryGroup
   D2D1_DP("m_pGeometryGroup: " & WSTR(m_pGeometryGroup))
   IF m_pGeometryGroup THEN m_pGeometryGroup->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1GeometryGroup interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1GeometryGroup) AS ID2D1GeometryGroup PTR
   RETURN geometry.m_pGeometryGroup
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1GeometryGroup interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GeometryGroup.@ () AS ID2D1GeometryGroup PTR PTR
   RETURN @m_pGeometryGroup
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1GeometryGroup interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GeometryGroup.CAST () AS ID2D1GeometryGroup PTR
   RETURN m_pGeometryGroup
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GeometryGroup.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pGeometryGroup)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1TransformedGeometry class
' Represents a composite geometry, composed of other ID2D1Geometry objects.
' ########################################################################################

' ========================================================================================
TYPE CID2D1TransformedGeometry EXTENDS CID2D1Geometry
Public:

   m_pTransformedGeometry AS ID2D1TransformedGeometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pTransformedGeometry AS ID2D1TransformedGeometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1TransformedGeometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1TransformedGeometry PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1TransformedGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1TransformedGeometry
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1TransformedGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1TransformedGeometry (BYVAL pTransformedGeometry AS ID2D1TransformedGeometry PTR)
   D2D1_DP("pTransformedGeometry - " & WSTR(pTransformedGeometry))
   m_pTransformedGeometry = pTransformedGeometry
   IF m_pTransformedGeometry THEN m_pTransformedGeometry->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pTransformedGeometry
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1TransformedGeometry
   D2D1_DP("m_pTransformedGeometry: " & WSTR(m_pTransformedGeometry))
   IF m_pTransformedGeometry THEN m_pTransformedGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1TransformedGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1TransformedGeometry) AS ID2D1TransformedGeometry PTR
   RETURN geometry.m_pTransformedGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1TransformedGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1TransformedGeometry.@ () AS ID2D1TransformedGeometry PTR PTR
   RETURN @m_pTransformedGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1TransformedGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1TransformedGeometry.CAST () AS ID2D1TransformedGeometry PTR
   RETURN m_pTransformedGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1TransformedGeometry.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pTransformedGeometry)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1PathGeometry class
' Represents a complex shape that may be composed of arcs, curves, and lines.
' ########################################################################################

' ========================================================================================
TYPE CID2D1PathGeometry EXTENDS CID2D1Geometry
Public:

   m_pPathGeometry AS ID2D1PathGeometry PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pPathGeometry AS ID2D1PathGeometry PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1PathGeometry PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1PathGeometry PTR
   DECLARE OPERATOR CAST () AS ID2D1Geometry PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1PathGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1PathGeometry
   D2D1_DP("Default")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1PathGeometry class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1PathGeometry (BYVAL pPathGeometry AS ID2D1PathGeometry PTR)
   D2D1_DP("pPathGeometry - " & WSTR(pPathGeometry))
   m_pPathGeometry = pPathGeometry
   IF m_pPathGeometry THEN m_pPathGeometry->AddRef
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pGeometry = m_pPathGeometry
   IF m_pPathGeometry = NULL THEN SetLastError(E_POINTER)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1PathGeometry
   D2D1_DP("m_pPathGeometry: " & WSTR(m_pPathGeometry))
   IF m_pPathGeometry THEN m_pPathGeometry->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1PathGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1PathGeometry) AS ID2D1PathGeometry PTR
   RETURN geometry.m_pPathGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1PathGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry.@ () AS ID2D1PathGeometry PTR PTR
   RETURN @m_pPathGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1PathGeometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry.CAST () AS ID2D1PathGeometry PTR
   RETURN m_pPathGeometry
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Geometry interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry.CAST () AS ID2D1Geometry PTR
   RETURN cast(ID2D1Geometry PTR, m_pPathGeometry)
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pPathGeometry)
END OPERATOR
' ========================================================================================


' ########################################################################################
' CID2D1PathGeometry1 class
' adds functionality to ID2D1PathGeometry.
' ########################################################################################

' ========================================================================================
TYPE CID2D1PathGeometry1 EXTENDS CID2D1PathGeometry
Public:

   m_pPathGeometry1 AS ID2D1PathGeometry1 PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pPathGeometry1 AS ID2D1PathGeometry1 PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1PathGeometry1 PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1PathGeometry1 PTR
   DECLARE OPERATOR CAST () AS ID2D1Resource PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1PathGeometry1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1PathGeometry1
   D2D1_DP("Deault")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1PathGeometry1 class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1PathGeometry1 (BYVAL pPathGeometry1 AS ID2D1PathGeometry1 PTR)
   D2D1_DP("pPathGeometry1 - " & WSTR(pPathGeometry1))
   m_pPathGeometry1 = pPathGeometry1
   IF m_pPathGeometry1 THEN m_pPathGeometry1->AddRef
   IF m_pPathGeometry THEN
      m_pPathGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pPathGeometry))
   END iF
   IF m_pGeometry THEN
      m_pGeometry->Release
      D2D1_DP("Release old factory: " & WSTR(m_pGeometry))
   END iF
   m_pPathGeometry = m_pPathGeometry1
   m_pGeometry = m_pPathGeometry1
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1PathGeometry1
   D2D1_DP("m_pPathGeometry1: " & WSTR(m_pPathGeometry1))
   IF m_pPathGeometry1 THEN m_pPathGeometry1->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1PathGeometry1 interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1PathGeometry1) AS ID2D1PathGeometry1 PTR
   RETURN geometry.m_pPathGeometry1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1PathGeometry1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry1.@ () AS ID2D1PathGeometry1 PTR PTR
   RETURN @m_pPathGeometry1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1PathGeometry1 interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry1.CAST () AS ID2D1PathGeometry1 PTR
   RETURN m_pPathGeometry1
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1Resource interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1PathGeometry1.CAST () AS ID2D1Resource PTR
   RETURN cast(ID2D1Resource PTR, m_pPathGeometry1)
END OPERATOR
' ========================================================================================

' ########################################################################################
' CID2D1SimplifiedGeometrySink class
' Inherited interface = IUnknown
' ########################################################################################
TYPE CID2D1SimplifiedGeometrySink

Public:

   m_pSimplifiedGeometrySink AS ID2D1SimplifiedGeometrySink PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pSimplifiedGeometrySink AS ID2D1SimplifiedGeometrySink PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1SimplifiedGeometrySink PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1SimplifiedGeometrySink PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Default constructor
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1SimplifiedGeometrySink
   D2D1_DP("Default")
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1SimplifiedGeometrySink class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1SimplifiedGeometrySink (BYVAL pSimplifiedGeometrySink AS ID2D1SimplifiedGeometrySink PTR)
   D2D1_DP("pSimplifiedGeometrySink - " & WSTR(pSimplifiedGeometrySink))
   m_pSimplifiedGeometrySink = pSimplifiedGeometrySink
   IF m_pSimplifiedGeometrySink = NULL THEN SetLastError(E_POINTER)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1SimplifiedGeometrySink
   D2D1_DP("m_pSimplifiedGeometrySink: " & WSTR(m_pSimplifiedGeometrySink))
   IF m_pSimplifiedGeometrySink THEN m_pSimplifiedGeometrySink->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1SimplifiedGeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1SimplifiedGeometrySink) AS ID2D1SimplifiedGeometrySink PTR
   RETURN geometry.m_pSimplifiedGeometrySink
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1SimplifiedGeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1SimplifiedGeometrySink.@ () AS ID2D1SimplifiedGeometrySink PTR PTR
   RETURN @m_pSimplifiedGeometrySink
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying CID2D1SimplifiedGeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1SimplifiedGeometrySink.CAST () AS ID2D1SimplifiedGeometrySink PTR
   RETURN m_pSimplifiedGeometrySink
END OPERATOR
' ========================================================================================

' ########################################################################################
' CID2D1GeometrySink class
' Inherited interface = ID2D1SimplifiedGeometrySink
' ########################################################################################
TYPE CID2D1GeometrySink EXTENDS CID2D1SimplifiedGeometrySink

Public:

   m_pGeometrySink AS ID2D1GeometrySink PTR

   DECLARE CONSTRUCTOR
   DECLARE CONSTRUCTOR (BYVAL pGeometrySink AS ID2D1GeometrySink PTR)
   DECLARE DESTRUCTOR
   DECLARE OPERATOR @ () AS ID2D1GeometrySink PTR PTR
   DECLARE OPERATOR CAST () AS ID2D1GeometrySink PTR

END TYPE
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GeometrySink class. Default constructor.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GeometrySink
   D2D1_DP("Default constructor - m_pGeometrySink = " & WSTR(m_pGeometrySink))
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Creates an instance of the CID2D1GeometrySink class.
' ========================================================================================
PRIVATE CONSTRUCTOR CID2D1GeometrySink (BYVAL pGeometrySink AS ID2D1GeometrySink PTR)
   D2D1_DP("pGeometrySink - " & WSTR(pGeometrySink))
   m_pGeometrySink = pGeometrySink
   IF m_pGeometrySink THEN m_pGeometrySink->AddRef
   IF m_pSimplifiedGeometrySink THEN
      m_pSimplifiedGeometrySink->Release
      D2D1_DP("Release old factory: " & WSTR(m_pSimplifiedGeometrySink))
   END iF
   m_pSimplifiedGeometrySink = m_pGeometrySink
   IF m_pGeometrySink = NULL THEN SetLastError(E_POINTER)
END CONSTRUCTOR
' ========================================================================================

' ========================================================================================
' Cleanup
' ========================================================================================
PRIVATE DESTRUCTOR CID2D1GeometrySink
   D2D1_DP("m_pGeometrySink: " & WSTR(m_pGeometrySink))
   IF m_pGeometrySink THEN m_pGeometrySink->Release
END DESTRUCTOR
' ========================================================================================

' ========================================================================================
' Returns the underlying ID2D1GeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR * (BYREF geometry AS CID2D1GeometrySink) AS ID2D1GeometrySink PTR
   RETURN geometry.m_pGeometrySink
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the address of the underlying ID2D1GeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GeometrySink.@ () AS ID2D1GeometrySink PTR PTR
   RETURN @m_pGeometrySink
END OPERATOR
' ========================================================================================
' ========================================================================================
' Returns the underlying ID2D1GeometrySink interface pointer
' ========================================================================================
PRIVATE OPERATOR CID2D1GeometrySink.CAST () AS ID2D1GeometrySink PTR
   RETURN m_pGeometrySink
END OPERATOR
' ========================================================================================

END NAMESPACE

