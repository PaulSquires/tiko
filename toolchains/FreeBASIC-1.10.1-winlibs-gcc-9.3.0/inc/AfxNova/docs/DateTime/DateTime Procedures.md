# Date and Time Procedures

Assorted date and time procedures.

**Include File**: AfxNova/AfxTime.inc.

| Name       | Description |
| ---------- | ----------- |
| [AfxAstroDay](#afxastroday) | Returns the Astronomical Day for any given date. |
| [AfxAstroDayOfWeek](#afxastrodayofweek) | Calculates the day of the week, Sunday through Monday, of a given date. |
| [AfxDateAddDays](#afxdateadddays) | Adds the specified number of days to a given date. |
| [AfxDateDiff](#afxdatediff) | Calculates the days of difference between two dates. |
| [AfxDayOfYear](#afxdayofyear) | Returns the day of the year, where Jan 1 is the first day of the year. |
| [AfxDaysBetween](#afxdaysbetween) | Returns the number of days between two given dates. |
| [AfxDaysInMonth](#afxdaysinmonth) | Returns the number of days in the specified month/year. |
| [AfxDaysInYear](#afxdaysinyyear) | Returns the number of days in the specified year. |
| [AfxFileTimeToDateStr](#afxdiletimetodatestr) | Converts a FILETIME type to a string containing the date based on the specified mask, e.g. "dd-MM-yyyy". |
| [AfxFileTimeToTime64](#afxfiletimetotime64) | Converts a FILETIME to a \_\_time64_t (LONGLONG) value. |
| [AfxFileTimeToTimeStr](#afxfiletimetotimestr) | Converts a FILETIME type to a string containing the time based on the specified mask, e.g. "hh':'mm':'ss". |
| [AfxGmtTime64](#afxgmttime64) | Converts a FILETIME to a \_\_time64_t (LONGLONG) value. |
| [AfxGregorianToJulian](#afxgregoriantojulian) | Converts a Gregorian date to a Julian date. The year must be a 4 digit year. |
| [AfxIsFirstDayOfMonth](#afxisfirstdayofmonth) | Returns TRUE if today is the first day of the month; False, otherwise. |
| [AfxIsLastDayOfMonth](#afxislastdayofmonth) | Returns TRUE if today is the last day of the month; False, otherwise. |
| [AfxIsLeapYear](#afxisleapyear) | Determines if a given year is a leap year or not. |
| [AfxIsValidFILETIME](#afxisvalidfiletime) | Checks if a FILETIME is valid. |
| [AfxJulianDayOfWeek](#afxjuliandayofweek) | Given a Julian date, returns the day of week. |
| [AfxJulianToGregorian](#afxjuliantogregorian) | Converts a Julian date to a Gregorian date. |
| [AfxJulianToGregorianStr](#afxjuliantogregorianstr) | Converts a Julian date to a Gregorian date based on the specified mask, e.g. "dd-MM-yyyy". |
| [AfxLocalDateStr](#afxlocaldatestr) | Returns the current local date based on the specified mask, e.g. "dd-MM-yyyy". |
| [AfxLocalDay](#afxlocalday) | Returns the current local day. The valid values are 1 through 31. |
| [AfxLocalDayName](#afxlocaldayname) | Returns the localized name of today. |
| [AfxLocalDayOfWeek](#afxlocaldayofweek) | Returns the current day of week. It is a numeric value in the range of 0-6 representing Sunday through Saturday: 0 = Sunday, 1 = Monday, etc. |
| [AfxLocalDayOfWeekName](#afxlocaldayofweekname) | Returns the localized name of the day of the week. |
| [AfxLocalDayOfWeekShortName](#afxlocaldayofweekshortname) | Returns the localized short name of the day of the week. |
| [AfxLocalDayShortName](#afxlocaldayshortname) | Returns the localized short name of today. |
| [AfxLocalFileTime](#afxlocalfiletime) | Returns the current local time as a FILETIME structure. |
| [AfxLocalHour](#afxlocalhour) | Returns the current local hour. The valid values are 0 through 23. |
| [AfxLocalMonth](#afxlocalmonth) | Returns the current local month. The valid values are 1 through 12 (1 = January, etc.). |
| [AfxLocalMonthName](#afxlocalmonthname) | Returns the localized name of today's local month. |
| [AfxLocalShortMonthName](#afxlocalshortmonthname) | Returns the localized short name of today's local month. |
| [AfxLocalSystemTime](#afxlocalsystemtime) | Returns the current local time as a SYSTEMTIME structure. |
| [AfxLocalTime64](#afxlocaltime64) | Converts a FILETIME to a \_\_time64_t (LONGLONG) value. |
| [AfxLocalTimeStr](#afxlocaltimestr) | Returns the current local time based on the specified mask, e.g. "hh':'mm':'ss". |
| [AfxLocalVariantTime](#afxlocalvarianttime) | Returns the local date and time as a DATE_ (double). |
| [AfxLocalYear](#afxlocalyear) | Returns the current local year. The valid values are 1601 through 30827. |
| [AfxLongDate](#afxlongdate) | Returns the current date in long format. |
| [AfxMakeTime64](#afxmaketime64) | Converts the local time to a calendar value. |
| [AfxMonthName](#afxmonthname) | Returns the localized name of the specified month. |
| [AfxQuadDateTime](#afxquaddatetime) | Returns the current date and time as a QUAD (8 bytes). In Free Basic, a QUAD is an ULONGLONG. |
| [AfxQuadDateToStr](#afxquaddatetostr) | Converts a date stored in a QUAD into a formatted date string. For example, to get the date string "Wed, Aug 31 94" use the following picture string: "ddd',' MMM dd yy".  In Free Basic, a QUAD is an ULONGLONG. |
| [AfxQuadTimeToStr](#afxquadtimetostr) | Converts a time stored in a QUAD into a formatted time string. For example, get the time string "11:29:40 PM" use the following picture string: "hh':'mm':'ss tt".  In Free Basic, a QUAD is an ULONGLONG. |
| [AfxNumberOfLeapYears](#afxnumberofleapyears) | Returns the number of leap years between two years. |
| [AfxShortDate](#afxshortdate) | Returns the current date in short format. |
| [AfxShortMonthName](#afxshortmonthname) | Returns the localized short name of the specified month. |
| [AfxSystemDay](#afxsystemday) | Returns the current system day. The valid values are 1 through 31. |
| [AfxSystemDayName](#afxsystemdayname) | Returns the localized name of today. |
| [AfxSystemDayOfWeek](#afxsystemdayofweek) | Returns the current day of week. It is a numeric value in the range of 0-6 representing Sunday through Saturday: 0 = Sunday, 1 = Monday, etc. |
| [AfxSystemDayShortName](#afxsystemdayshortname) | Returns the localized short name of today. |
| [AfxSystemFileTime](#afxsystemfiletime) | Returns the current system time as a FILETIME structure. |
| [AfxSystemHour](#afxsystemhour) | Returns the current system hour. The valid values are 0 through 23. |
| [AfxSystemMonth](#afxsystemmonth) | Returns the current system month. The valid values are 1 through 12 (1 = January, etc.). |
| [AfxSystemMonthName](#afxsystemmonthname) | Returns the localized name of today's system month. |
| [AfxSystemShortMonthName](#afxsystemshortmonthname) | Returns the localized short name of today's system month. |
| [AfxSystemSystemTime](#afxsystemsystemtime) | Returns the current system time as a SYSTEMTIME structure. |
| [AfxSystemTimeToTime64](#afxsystemtimetotime64) | Converts a system time to a \_\_time64_t (LONGLONG). |
| [AfxSystemTimeToDateStr](#afxsystemtimetodatestr) | Converts a SYSTEMTIME type to a string containing the date based on the specified mask, e.g. "dd-MM-yyyy". |
| [AfxSystemTimeToTimeStr](#afxsystemtimetotimestr) | Converts a SYSTEMTIME type to a string containing the time based on the specified mask, e.g. "hh':'mm':'ss". |
| [AfxSystemTimeToVariantTime](#afxsystemtimetovarianttime) | Converts a SYSTEMTIME to a DATE_ (double). |
| [AfxSystemYear](#afxsystemyear) | Returns the current system year. The valid values are 1601 through 30827. |
| [AfxTime64](#afxtime64) | Returns the time as seconds elapsed since midnight, January 1, 1970. |
| [AfxTime64ToFileTime](#afxtime64tofiletime) | Converts a \_\_time64_t (LONGLONG) value to a FILETIME structure. |
| [AfxTime64ToSystemTime](#afxtime64tosystemtime) | Converts a \_\_time64_t (LONGLONG) to a SYSTEMTIME structure. |
| [AfxTimeZoneBias](#afxtimezonebias) | Current bias for local time translation. The bias is the difference between Coordinated Universal Time (UTC) and local time. All translations between UTC and local time are based on the following formula: UTC = local time + bias. Units = minutes. |
| [AfxTimeZoneDaylightBias](#afxtimezonedaylightbias) | Bias value to be used during local time translations that occur during daylight saving time. This property is ignored if a value for the **DaylightDay** property is not supplied. The value of this property is added to the Bias property to form the bias used during daylight time. In most time zones, the value of this property is -60. Units = minutes. |
| [AfxTimeZoneDaylightDay](#afxtimezonedaylightday) | **DaylightDayOfWeek** of the **DaylightMonth** when the transition from standard time to daylight saving time occurs on this operating system. |
| [AfxTimeZoneDaylightDayOfWeek](#afxtimezonedaylightdayofweek) | Day of the week when the transition from standard time to daylight saving time occurs on an operating system. |
| [AfxTimeZoneDaylightHour](#afxtimezonedaylighthour) | Hour of the day when the transition from standard time to daylight saving time occurs on an operating system. |
| [AfxTimeZoneDaylightMinute](#afxtimezonedaylightminute) | Minute of the **DaylightHour** when the transition from standard time to daylight saving time occurs on an operating system. |
| [AfxTimeZoneDaylightMonth](#afxtimezonedaylightmonth) | Month when the transition from standard time to daylight saving time occurs on an operating system. |
| [AfxTimeZoneDaylightName](#afxtimezonedaylightname) | A description for daylight saving time. For example, "EST" could indicate Eastern Standard Time. This string can be empty. |
| [AfxTimeZoneId](#afxtimezoneid) | Returns the time zone identifier. |
| [AfxTimeZoneIsDaylightSavingTime](#afxtimezoneisdaylightsavingtime) | Indicates whether the system is operating in the range covered by the DaylightDate member of the TIME_ZONE_INFORMATION structure. |
| [AfxTimeZoneIsStandardSavingTime](#afxtimezoneisstandardsavingtime) | Indicates whether the system is operating in the range covered by the StandardDate member of the TIME_ZONE_INFORMATION structure. |
| [AfxTimeZoneStandardDay](#afxtimezonestandardday) | **StandardDayOfWeek** of the **StandardMonth** when the transition from daylight saving time to standard time occurs on an operating system. |
| [AfxTimeZoneStandardDayOfWeek](#afxtimezonestandarddayofweek) | Day of the week when the transition from daylight saving time to standard time occurs on an operating system. |
| [AfxTimeZoneStandardHour](#afxtimezonestandardhour) |Hour of the day when the transition from daylight saving time to standard time occurs on an operating system. |
| [AfxTimeZoneStandardMinute](#afxtimezonestandardminute) | Minute of the **StandardHour** when the transition from standard time to daylight saving time occurs on an operating system. |
| [AfxTimeZoneStandardMonth](#afxtimezonestandardmonth) | Month when the transition from daylight saving time to standard time occurs on an operating system. |
| [AfxTimeZoneStandardName](#afxtimezonestandardname) | A description for standard time. For example, "EST" could indicate Eastern Standard Time. This string can be empty. |
| [AfxUnixTimeToFileTime](#afxunixtimetofiletime) | Comverts Unix time to FileTime. |
| [AfxUnixTimeToSystemTime](#afxunixtimetosystemtime) | Comverts Unix time to SystemTime. |
| [AfxUnixDateStr](#afxunixdatestr) | Retuns the current Unix date based on the specified mask, e.g. "dd-MM-yyyy". |
| [AfxUnixTimeStr](#afxunixtimestr) | Retuns the current Unix time based on the specified mask, e.g. "hh':'mm':'ss"." |
| [AfxUtcDateStr](#afxutcdatestr) | Returns the current local date based on the specified mask, e.g. "dd-MM-yyyy". |
| [AfxUtcTimeStr](#afxutctimestr) | Returns the current UTC time based on the specified mask, e.g. "hh':'mm':'ss". |
| [AfxVariantDateTimeToStr](#afxvariantdatetimetostr) | Converts a DATE_ type to a string. |
| [AfxVariantDateToStr](#afxvariantdatetostr) | Converts a DATE_ type to a string containing only the date. |
| [AfxVariantTimeToStr](#afxvarianttimetostr) | Converts a DATE_ type to a string containing only the time. |
| [AfxVariantTimeToSystemTime](#afxvarianttimetosystemtime) | Converts a DATE_ (double) to a SYSTEMTIME. |
| [AfxWeekNumber](#afxweeknumber) | Returns the week number for a given date. The year must be a 4 digit year. |
| [AfxWeekOne](#afxweekone) | Returns the first day of the first week of a year. The year must be a 4 digit year. |
| [AfxWeeksInMonth](#afxweeksinmonth) | Returns the number of weeks in the specified month. Will be 4 or 5. |
| [AfxWeeksInYear](#afxweeksinyear) | Returns the number of weeks in the year, where weeks are taken to start on Monday. Will be 52 or 53. |

---

## AfxAstroDay

Returns the Astronomical Day for any given date.

```
FUNCTION AfxAstroDay (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A day number (1-31). |
| *nMonth* | A month number (1-12). |
| *nYear* | A four digit year. |

#### Return value

The astronomical day.

#### Remarks

Among other things, can be used to find the number of days between any two dates, e.g.:

```
PRINT AfxAstroDay(1, 3, -12400) - AfxAstroDay(28, 2, -12400)  ' Prints 2
PRINT AfxAstroDay(1, 3, 12000) - AfxAstroDay(28, 2, -12000)  ' Prints 8765822
PRINT AfxAstroDay(28, 2, 1902) - AfxAstroDay(1, 3, 1898)  ' Prints 1459 days
```

---

## AfxAstroDayOfWeek

Calculates the day of the week, Sunday through Monday, of a given date.

```
FUNCTION AfxAstroDayOfWeek (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A day number (1-31). |
| *nMonth* | A month number (1-12). |
| *nYear* | A four digit year. |

#### Return value

A number between 0-6, where 0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday.

---

## AfxDateAddDays

Adds the specified number of days to a given date.

```
FUNCTION AfxDateAddDays (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG, _
   BYVAL nDays AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A day number (1-31). |
| *nMonth* | A month number (1-12). |
| *nYear* | A four digit year. |
| *nDays* | The number of days to add (or subtract, if it is negative). |

#### Return value

The new date in Julian format. To convert it to Gregorian, call functions such **AfxJulianToGregorian** or **AfxJulianToGregorianStr**.

---

## AfxDateDiff

Calculates the days of difference between two dates.

```
FUNCTION AfxDateDiff (BYVAL nDay1 AS LONG, BYVAL nMonth1 AS LONG, BYVAL nYear1 AS LONG, _
   BYVAL nDay2 AS LONG, BYVAL nMonth2 AS LONG, BYVAL nYear2 AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay1* | A day number (1-31). |
| *nMonth1* | A month number (1-12). |
| *nYear1* | A four digit year. |
| *nDay2* | A day number (1-31). |
| *nMonth2* | A month number (1-12). |
| *nYear2* | A four digit year. |

#### Return value

The days of difference between the two dates.

---

## AfxDayOfYear

Returns the day of the year, where Jan 1 is the first day of the year.

```
FUNCTION AfxDayOfYear (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A day number (1-31). |
| *nMonth* | A month number (1-12). |
| *nYear* | A four digit year. |

#### Return value

The day of the year.

---

## AfxDaysBetween

Returns the number of days between two given dates.

```
FUNCTION AfxDaysBetween (BYVAL nDay1 AS LONG, BYVAL nMonth1 AS LONG, BYVAL nYear1 AS LONG, _
   BYVAL nDay2 AS LONG, BYVAL nMonth2 AS LONG, BYVAL nYear2 AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay1* | A day number (1-31). |
| *nMonth1* | A month number (1-12). |
| *nYear1* | A four digit year. |
| *nDay2* | A day number (1-31). |
| *nMonth2* | A month number (1-12). |
| *nYear2* | A four digit year. |

#### Return value

The number of days.

---

## AfxDaysInMonth

Returns the number of days in the specified month/year.

```
FUNCTION AfxDaysInMonth (BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nMonth* | A month ordinal number (1-12). |
| *nYear* | A four digit year. |

#### Return value

The number of days in the specified month/year.

---

## AfxDaysInYear

Returns the number of days in the specified year.

```
FUNCTION AfxDaysInYear (BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nYear* | A four digit year. |

#### Return value

The number of days: 365 (not leap year) or 366 (leap year).

---

## AfxFileTimeToDateStr

Converts a FILETIME type to a string containing the date based on the specified mask, e.g. "dd-MM-yyyy".

```
FUNCTION AfxFileTimeToDateStr (BYREF ft AS FILETIME, BYREF wszMask AS WSTRING, _
   BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *ft* | A FILETIME structure. |
| *wszMask* | A picture string that is used to form the date.<br>The format types "d", and "y" must be lowercase and the letter "M" must be uppercase.<br>For example, to get the date string "Wed, Aug 31 94", the application uses the picture string "ddd',' MMM dd yy". |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

The following table defines the format types used to represent days.

| Format type | Meaning |
| ----------- | ----------- |
| d | Day of the month as digits without leading zeros for single-digit days. |
| dd | Day of the month as digits with leading zeros for single-digit days. |
| ddd | Abbreviated day of the week, for example, "Mon" in English (United States). |
| dddd | Day of the week. |

The following table defines the format types used to represent months.

| Format type | Meaning |
| ----------- | ----------- |
| M | Month as digits without leading zeros for single-digit months. |
| MM | Month as digits with leading zeros for single-digit months. |
| MMM | Abbreviated month, for example, "Nov" in English (United States). |
| MMMM | Month value, for example, "November" for English (United States), and "Noviembre" for Spanish (Spain). |

The following table defines the format types used to represent years.

| Format type | Meaning |
| ----------- | ----------- |
| y | Year represented only by the last digit. |
| yy | Year represented only by the last two digits. A leading zero is added for single-digit years. |
| yyyy | Year represented by a full four or five digits, depending on the calendar used. Thai Buddhist and Korean calendars have five-digit years. The "yyyy" pattern shows five digits for these two calendars, and four digits for all other supported calendars. Calendars that have single-digit or two-digit years, such as for the Japanese Emperor era, are represented differently. A single-digit year is represented with a leading zero, for example, "03". A two-digit year is represented with two digits, for example, "13". No additional leading zeros are displayed. |
| yyyyy | Behaves identically to "yyyy". |

#### Return value

The formatted date.

---

## AfxFileTimeToTime64

Converts a FILETIME to a \_\_time64_t (LONGLONG) value.

```
FUNCTION AfxFileTimeToTime64 (BYREF ft AS FILETIME) AS LONGLONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *ft* | A FILETIME structure. |

#### Return value

The converted time.

---

## AfxFileTimeToTimeStr

Converts a FILETIME type to a string containing the time based on the specified mask, e.g. "hh':'mm':'ss".

```
FUNCTION AfxFileTimeToTimeStr (BYREF ft AS FILETIME, BYREF wszMask AS WSTRING, _
   BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *ft* | A FILETIME structure. |
| *wszMask* | A picture string that is used to form the time. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |


The application can use the following elements to construct a format picture string. If spaces are used to separate the elements in the format string, these spaces appear in the same location in the output string. The letters must be in uppercase or lowercase as shown, for example, "ss", not "SS". Characters in the format string that are enclosed in single quotation marks appear in the same location and unchanged in the output string.

| Picture    | Meaning |
| ---------- | ----------- |
| h | Hours with no leading zero for single-digit hours; 12-hour clock |
| hh | Hours with leading zero for single-digit hours; 12-hour clock |
| H | Hours with no leading zero for single-digit hours; 24-hour clock |
| HH | Hours with leading zero for single-digit hours; 24-hour clock |
| m | Minutes with no leading zero for single-digit minutes |
| mm | Minutes with leading zero for single-digit minutes |
| s | Seconds with no leading zero for single-digit seconds |
| ss | Seconds with leading zero for single-digit seconds |
| t | One character time marker string, such as A or P |
| tt | Multi-character time marker string, such as AM or PM |

#### Return value

The formatted time.

---

## AfxGmtTime64

Converts a FILETIME to a \_\_time64_t (LONGLONG) value.

```
FUNCTION AfxGmtTime64 (BYVAL t64 AS LONGLONG) AS tm
```

| Parameter  | Description |
| ---------- | ----------- |
| *t64* | A \_\_time64_t (LONGLONG) value. The time is represented as seconds elapsed since midnight (00:00:00), January 1, 1970, coordinated universal time (UTC). |

#### Return value

Returns a tm structure. The fields of the returned structure hold the evaluated value of the time argument in UTC rather than in local time. 

The fields of the structure type tm store the following values, each of which is an int:

tm_sec : Seconds after minute (0 – 59).<br>
tm_min : Minutes after hour (0 – 59).<br>
tm_hour : Hours after midnight (0 – 23).<br>
tm_mday : Day of month (1 – 31).<br>
tm_mon : Month (0 – 11; January = 0).<br>
tm_year : Year (current year minus 1900).<br>
tm_wday : Day of week (0 – 6; Sunday = 0).<br>
tm_yday : Day of year (0 – 365; January 1 = 0).<br>
tm_isdst : Positive value if daylight saving time is in effect; 0 if daylight saving time is not in effect; negative value if status of daylight saving time is unknown.

#### Remarks

Replacement for **\_gmtime64**, not available in msvcrt.dll.

---

## AfxGregorianToJulian

Converts a Gregorian date to a Julian date. The year must be a 4 digit year.

```
FUNCTION AfxGregorianToJulian (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A day number (1-31). |
| *nMonth* | A month number (1-12). |
| *nYear* | A four digit year. |

#### Return value

The converted date.

---

## AfxIsFirstDayOfMonth

Returns TRUE if today is the first day of the month; False, otherwise.

```
FUNCTION AfxIsFirstDayOfMonth () AS BOOLEAN
```

---

## AfxIsLastDayOfMonth

Returns TRUE if today is the last day of the month; False, otherwise.

```
FUNCTION AfxIsLastDayOfMonth () AS BOOLEAN
```

---

## AfxIsLeapYear

Determines if a given year is a leap year or not.

```
FUNCTION AfxIsLeapYear (BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nYear* | A four digit year. |

---

## AfxIsValidFILETIME

Checks if a FILETIME is valid.

```
FUNCTION AfxIsValidFILETIME (BYREF ft AS FILETIME) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *ft* | The FILETIME structure to check. |

---

## AfxJulianDayOfWeek

Given a Julian date, returns the day of week.

```
FUNCTION AfxJulianDayOfWeek (BYVAL nJulian AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nJulian* | The Julian date. |

#### Return value

A number between 0-6, where 0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday.

---

## AfxJulianToGregorian

Converts a Julian date to a Gregorian date.

```
FUNCTION AfxJulianToGregorian (BYVAL nJulian AS LONG, BYVAL nDay AS LONG, _
   BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nJulian* | The Julian date. |
| *nDay* | Out. The day (1-31). |
| *nMonth* | Out. The month (1-12). |
| *nYear* | Out. The four digit year. |

---

## AfxJulianToGregorianStr

Converts a Julian date to a Gregorian date based on the specified mask, e.g. "dd-MM-yyyy".

```
FUNCTION AfxJulianToGregorianStr (BYREF wszMask AS WSTRING, BYVAL nJulian AS LONG) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszMask* | A picture string that is used to form the date.<br>The format types "d", and "y" must be lowercase and the letter "M" must be uppercase.<br>For example, to get the date string "Wed, Aug 31 94", the application uses the picture string "ddd',' MMM dd yy". |
| *nJulian* | The Julian date. |

The following table defines the format types used to represent days.

| Format type | Meaning |
| ----------- | ----------- |
| d | Day of the month as digits without leading zeros for single-digit days. |
| dd | Day of the month as digits with leading zeros for single-digit days. |
| ddd | Abbreviated day of the week, for example, "Mon" in English (United States). |
| dddd | Day of the week. |

The following table defines the format types used to represent months.

| Format type | Meaning |
| ----------- | ----------- |
| M | Month as digits without leading zeros for single-digit months. |
| MM | Month as digits with leading zeros for single-digit months. |
| MMM | Abbreviated month, for example, "Nov" in English (United States). |
| MMMM | Month value, for example, "November" for English (United States), and "Noviembre" for Spanish (Spain). |

The following table defines the format types used to represent years.

| Format type | Meaning |
| ----------- | ----------- |
| y | Year represented only by the last digit. |
| yy | Year represented only by the last two digits. A leading zero is added for single-digit years. |
| yyyy | Year represented by a full four or five digits, depending on the calendar used. Thai Buddhist and Korean calendars have five-digit years. The "yyyy" pattern shows five digits for these two calendars, and four digits for all other supported calendars. Calendars that have single-digit or two-digit years, such as for the Japanese Emperor era, are represented differently. A single-digit year is represented with a leading zero, for example, "03". A two-digit year is represented with two digits, for example, "13". No additional leading zeros are displayed. |
| yyyyy | Behaves identically to "yyyy". |

#### Return value

The formatted date.

---

## AfxLocalDateStr

Returns the current local date based on the specified mask, e.g. "dd-MM-yyyy".

```
FUNCTION AfxLocalDateStr (BYREF wszMask AS WSTRING, BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszMask* | A picture string that is used to form the date.<br>The format types "d", and "y" must be lowercase and the letter "M" must be uppercase.<br>For example, to get the date string "Wed, Aug 31 94", the application uses the picture string "ddd',' MMM dd yy". |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

The following table defines the format types used to represent days.

| Format type | Meaning |
| ----------- | ----------- |
| d | Day of the month as digits without leading zeros for single-digit days. |
| dd | Day of the month as digits with leading zeros for single-digit days. |
| ddd | Abbreviated day of the week, for example, "Mon" in English (United States). |
| dddd | Day of the week. |

The following table defines the format types used to represent months.

| Format type | Meaning |
| ----------- | ----------- |
| M | Month as digits without leading zeros for single-digit months. |
| MM | Month as digits with leading zeros for single-digit months. |
| MMM | Abbreviated month, for example, "Nov" in English (United States). |
| MMMM | Month value, for example, "November" for English (United States), and "Noviembre" for Spanish (Spain). |

The following table defines the format types used to represent years.

| Format type | Meaning |
| ----------- | ----------- |
| y | Year represented only by the last digit. |
| yy | Year represented only by the last two digits. A leading zero is added for single-digit years. |
| yyyy | Year represented by a full four or five digits, depending on the calendar used. Thai Buddhist and Korean calendars have five-digit years. The "yyyy" pattern shows five digits for these two calendars, and four digits for all other supported calendars. Calendars that have single-digit or two-digit years, such as for the Japanese Emperor era, are represented differently. A single-digit year is represented with a leading zero, for example, "03". A two-digit year is represented with two digits, for example, "13". No additional leading zeros are displayed. |
| yyyyy | Behaves identically to "yyyy". |

#### Return value

The current local date in string format.

---
---

# AfxLocalDay

Returns the current local day. The valid values are 1 through 31.

```
FUNCTION AfxLocalDay () AS WORD
```
---

## AfxLocalDayName

Returns the current local day. The valid values are 1 through 31.

```
FUNCTION AfxLocalDayName (BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxLocalDayOfWeek

Returns the current day of week. It is a numeric value in the range of 0-6 representing Sunday through Saturday: 0 = Sunday, 1 = Monday, etc.

```
FUNCTION AfxLocalDayOfWeek () AS WORD
```
---

## AfxLocalDayOfWeekName

Returns the localized name of the day of the week.

```
FUNCTION AfxLocalDayOfWeekName (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG, _
   BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A number between 1-31. |
| *nMonth* | A number between 1-12. |
| *nYear* | A four digit year, e.g. 2011. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxLocalDayOfWeekShortName

Returns the localized short name of the day of the week.

```
FUNCTION AfxLocalDayOfWeekShortName (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, _
   BYVAL nYear AS LONG, BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A number between 1-31. |
| *nMonth* | A number between 1-12. |
| *nYear* | A four digit year, e.g. 2011. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxLocalDayShortName

Returns the localized short name of today.

```
FUNCTION AfxLocalDayShortName (BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```
---

## AfxLocalFileTime

Returns the current local time as a FILETIME structure.

```
FUNCTION AfxLocalFileTime () AS FILETIME
```
---

## AfxLocalHour

Returns the current local hour. The valid values are 0 through 23.

```
FUNCTION AfxLocalHour () AS WORD
```
---

## AfxLocalMonth

Returns the current local month. The valid values are 1 through 12 (1 = January, etc.).

```
FUNCTION AfxLocalMonth () AS WORD
```
---

## AfxLocalMonthName

Returns the localized name of today's local month.

```
FUNCTION AfxLocalMonthName (BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxLocalShortMonthName

Returns the localized short name of today's local month.

```
FUNCTION AfxLocalShortMonthName (BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxLocalSystemTime

Returns the current local time as a SYSTEMTIME structure.

```
FUNCTION AfxLocalSystemTime () AS SYSTEMTIME
```
---

## AfxLocalTime64

Converts a FILETIME to a \_\_time64_t (LONGLONG) value.

```
FUNCTION AfxLocalTime64 (BYVAL t64 AS LONGLONG) AS tm
```

| Parameter  | Description |
| ---------- | ----------- |
| *t64* | A \_\_time64_t (LONGLONG) value.  The time is represented as seconds elapsed since midnight (00:00:00), January 1, 1970, coordinated universal time (UTC). |

#### Return value

Returns a tm structure. The fields of the returned structure hold the evaluated value of the time argument in UTC rather than in local time.

---

## AfxLocalTimeStr

Returns the current local time based on the specified mask, e.g. "hh':'mm':'ss".

```
FUNCTION AfxLocalTimeStr (BYREF wszMask AS WSTRING, BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszMask* | A picture string that is used to form the time. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

Picture string used to form the time.

| Picture    | Meaning |
| ---------- | ----------- |
| h | Hours with no leading zero for single-digit hours; 12-hour clock |
| hh | Hours with leading zero for single-digit hours; 12-hour clock |
| H | Hours with no leading zero for single-digit hours; 24-hour clock |
| HH | Hours with leading zero for single-digit hours; 24-hour clock |
| m | Minutes with no leading zero for single-digit minutes |
| mm | Minutes with leading zero for single-digit minutes |
| s | Seconds with no leading zero for single-digit seconds |
| ss | Seconds with leading zero for single-digit seconds |
| t | One character time marker string, such as A or P |
| tt | Multi-character time marker string, such as AM or PM |

#### Return value

The formatted current local time.

---

### AfxUnixTimeToFileTime

Comverts Unix time to FileTime.

```
FUNCTION AfxUnixTimeToFileTime (BYVAL unixTime AS DWORD) AS FILETIME
```
| Parameter  | Description |
| ---------- | ----------- |
| *unixTime* | The Unix time measures time by the number of non-leap seconds that have elapsed since 00:00:00 UTC on 1 January 1970 |

#### Return value

Returns a FileTime structure that contains a 64-bit value representing the number of 100-nanosecond intervals since January 1, 1601 (UTC).

---

### AfxUnixTimeToSystemTime

Comverts Unix time to SystemTime.

```
FUNCTION AfxUnixTimeToSystemTime (BYVAL unixTime AS DWORD) AS SYSTEMTIME
```
| Parameter  | Description |
| ---------- | ----------- |
| *unixTime* | The Unix time measures time by the number of non-leap seconds that have elapsed since 00:00:00 UTC on 1 January 1970 |

#### Return value

Returns a SystemTime structure that specifies a date and time, using individual members for the month, day, year, weekday, hour, minute, second, and millisecond. The time is either in coordinated universal time (UTC) or local time, depending on the function that is being called.

---

## AfxUnixDateStr

Retuns an Unix date based on the specified mask, e.g. "dd-MM-yyyy".

```
FUNCTION AfxUnixDateStr (BYVAL unixTime AS DWORD, BYREF wszMask AS WSTRING, _
   BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *unixTime* | The Unix time value. |
| *wszMask* | A picture string that is used to form the date.<br>The format types "d", and "y" must be lowercase and the letter "M" must be uppercase.<br>For example, to get the date string "Wed, Aug 31 94", the application uses the picture string "ddd',' MMM dd yy". |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

The following table defines the format types used to represent days.

| Format type | Meaning |
| ----------- | ----------- |
| d | Day of the month as digits without leading zeros for single-digit days. |
| dd | Day of the month as digits with leading zeros for single-digit days. |
| ddd | Abbreviated day of the week, for example, "Mon" in English (United States). |
| dddd | Day of the week. |

The following table defines the format types used to represent months.

| Format type | Meaning |
| ----------- | ----------- |
| M | Month as digits without leading zeros for single-digit months. |
| MM | Month as digits with leading zeros for single-digit months. |
| MMM | Abbreviated month, for example, "Nov" in English (United States). |
| MMMM | Month value, for example, "November" for English (United States), and "Noviembre" for Spanish (Spain). |

The following table defines the format types used to represent years.

| Format type | Meaning |
| ----------- | ----------- |
| y | Year represented only by the last digit. |
| yy | Year represented only by the last two digits. A leading zero is added for single-digit years. |
| yyyy | Year represented by a full four or five digits, depending on the calendar used. Thai Buddhist and Korean calendars have five-digit years. The "yyyy" pattern shows five digits for these two calendars, and four digits for all other supported calendars. Calendars that have single-digit or two-digit years, such as for the Japanese Emperor era, are represented differently. A single-digit year is represented with a leading zero, for example, "03". A two-digit year is represented with two digits, for example, "13". No additional leading zeros are displayed. |
| yyyyy | Behaves identically to "yyyy". |

#### Return value

The Unix date in string format.

#### Usage example
```
PRINT AfxUnixDateStr(AfxWindowsInstallDate, "dd-MM-yyyy")
```
---

## AfxUnixTimeStr

Retuns an Unix time based on the specified mask, e.g. "hh':'mm':'ss"."

```
FUNCTION AfxUnixTimeStr (BYVAL unixTime AS DWORD, BYREF wszMask AS WSTRING, _
   BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *unixTime* | The Unix time value. |
| *wszMask* | A picture string that is used to form the time. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

Picture string used to form the time.

| Picture    | Meaning |
| ---------- | ----------- |
| h | Hours with no leading zero for single-digit hours; 12-hour clock |
| hh | Hours with leading zero for single-digit hours; 12-hour clock |
| H | Hours with no leading zero for single-digit hours; 24-hour clock |
| HH | Hours with leading zero for single-digit hours; 24-hour clock |
| m | Minutes with no leading zero for single-digit minutes |
| mm | Minutes with leading zero for single-digit minutes |
| s | Seconds with no leading zero for single-digit seconds |
| ss | Seconds with leading zero for single-digit seconds |
| t | One character time marker string, such as A or P |
| tt | Multi-character time marker string, such as AM or PM |

#### Return value

The formatted Unix time.

#### Usage example
```
PRINT AfxUnixTimeStr(AfxWindowsInstallDate, "hh':'mm':'ss")
```
---

## AfxUtcDateStr

Returns the current UTC date based on the specified mask, e.g. "dd-MM-yyyy".

```
FUNCTION AfxUtcDateStr (BYREF wszMask AS WSTRING, BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszMask* | A picture string that is used to form the date.<br>The format types "d", and "y" must be lowercase and the letter "M" must be uppercase.<br>For example, to get the date string "Wed, Aug 31 94", the application uses the picture string "ddd',' MMM dd yy". |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

The following table defines the format types used to represent days.

| Format type | Meaning |
| ----------- | ----------- |
| d | Day of the month as digits without leading zeros for single-digit days. |
| dd | Day of the month as digits with leading zeros for single-digit days. |
| ddd | Abbreviated day of the week, for example, "Mon" in English (United States). |
| dddd | Day of the week. |

The following table defines the format types used to represent months.

| Format type | Meaning |
| ----------- | ----------- |
| M | Month as digits without leading zeros for single-digit months. |
| MM | Month as digits with leading zeros for single-digit months. |
| MMM | Abbreviated month, for example, "Nov" in English (United States). |
| MMMM | Month value, for example, "November" for English (United States), and "Noviembre" for Spanish (Spain). |

The following table defines the format types used to represent years.

| Format type | Meaning |
| ----------- | ----------- |
| y | Year represented only by the last digit. |
| yy | Year represented only by the last two digits. A leading zero is added for single-digit years. |
| yyyy | Year represented by a full four or five digits, depending on the calendar used. Thai Buddhist and Korean calendars have five-digit years. The "yyyy" pattern shows five digits for these two calendars, and four digits for all other supported calendars. Calendars that have single-digit or two-digit years, such as for the Japanese Emperor era, are represented differently. A single-digit year is represented with a leading zero, for example, "03". A two-digit year is represented with two digits, for example, "13". No additional leading zeros are displayed. |
| yyyyy | Behaves identically to "yyyy". |

#### Return value

The current UTC date in string format.

---

## AfxUtcTimeStr

Returns the current UTC time based on the specified mask, e.g. "hh':'mm':'ss".

```
FUNCTION AfxUtcTimeStr (BYREF wszMask AS WSTRING, BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszMask* | A picture string that is used to form the time. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

Picture string used to form the time.

| Picture    | Meaning |
| ---------- | ----------- |
| h | Hours with no leading zero for single-digit hours; 12-hour clock |
| hh | Hours with leading zero for single-digit hours; 12-hour clock |
| H | Hours with no leading zero for single-digit hours; 24-hour clock |
| HH | Hours with leading zero for single-digit hours; 24-hour clock |
| m | Minutes with no leading zero for single-digit minutes |
| mm | Minutes with leading zero for single-digit minutes |
| s | Seconds with no leading zero for single-digit seconds |
| ss | Seconds with leading zero for single-digit seconds |
| t | One character time marker string, such as A or P |
| tt | Multi-character time marker string, such as AM or PM |

#### Return value

The formatted current UTC time.

---

## AfxLocalVariantTime

Returns the local date and time as a DATE_ (double).

```
FUNCTION AfxLocalVariantTime () AS DATE_
```
---

## AfxLocalYear

Returns the current local year. The valid values are 1601 through 30827.

```
FUNCTION AfxLocalYear () AS WORD
```
---

## AfxLongDate

Returns the current date in long format.

```
FUNCTION AfxLongDate (BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxMakeTime64

Converts the local time to a calendar value.

```
FUNCTION AfxMakeTime64 (BYREF _tm AS tm) AS LONGLONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *tm* | A tm structure. |

The fields of the structure type tm store the following values, each of which is an int:

tm_sec : Seconds after minute (0 – 59).<br>
tm_min : Minutes after hour (0 – 59).<br>
tm_hour : Hours after midnight (0 – 23).<br>
tm_mday : Day of month (1 – 31).<br>
tm_mon : Month (0 – 11; January = 0).<br>
tm_year : Year (current year minus 1900).<br>
tm_wday : Day of week (0 – 6; Sunday = 0).<br>
tm_yday : Day of year (0 – 365; January 1 = 0).<br>
tm_isdst : Positive value if daylight saving time is in effect; 0 if daylight saving time is not in effect; negative value if status of daylight saving time is unknown.

#### Return value

The converted time.

---

## AfxMonthName

Returns the localized name of the specified month.

```
FUNCTION AfxMonthName (BYVAL nMonth AS LONG, BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *nMonth* | Valid values are between 1 and 12. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxNumberOfLeapYears

Returns the number of leaos years between two years.

```
FUNCTION AfxNumberOfLeapYears (BYVAL year1 AS LONG, BYVAL years2 AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *year1* | The starting year. |
| *year2* | The ending year. |

---

## AfxQuadDateTime

Returns the current date and time as a QUAD (8 bytes). In Free Basic, a QUAD is an ULONGLONG.

```
FUNCTION AfxQuadDateTime () AS ULONGLONG
```
---

## AfxQuadDateToStr

Converts a date stored in a QUAD into a formatted date string. For example, to get the date string "Wed, Aug 31 94" use the following picture string: "ddd',' MMM dd yy".  In Free Basic, a QUAD is an ULONGLONG.

```
FUNCTION AfxQuadDateToStr (BYREF wszMask AS WSTRING, BYVAL ullTime AS ULONGLONG, _
   BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszMask* | A picture string that is used to form the date.<br>The format types "d", and "y" must be lowercase and the letter "M" must be uppercase.<br>For example, to get the date string "Wed, Aug 31 94", the application uses the picture string "ddd',' MMM dd yy". |
| *ullTime* | The datetime variable. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

#### Return value

The formatted date.

---

## AfxQuadTimeToStr

Converts a time stored in a QUAD into a formatted time string. For example, get the time string "11:29:40 PM" use the following picture string: "hh':'mm':'ss tt".  In Free Basic, a QUAD is an ULONGLONG.

```
FUNCTION AfxQuadTimeToStr (BYREF wszMask AS WSTRING, BYVAL ullTime AS ULONGLONG, _
   BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszMask* | A picture string that is used to form the time. |
| *ullTime* | The datetime variable. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

Picture string used to form the time.

| Picture    | Meaning |
| ---------- | ----------- |
| h | Hours with no leading zero for single-digit hours; 12-hour clock |
| hh | Hours with leading zero for single-digit hours; 12-hour clock |
| H | Hours with no leading zero for single-digit hours; 24-hour clock |
| HH | Hours with leading zero for single-digit hours; 24-hour clock |
| m | Minutes with no leading zero for single-digit minutes |
| mm | Minutes with leading zero for single-digit minutes |
| s | Seconds with no leading zero for single-digit seconds |
| ss | Seconds with leading zero for single-digit seconds |
| t | One character time marker string, such as A or P |
| tt | Multi-character time marker string, such as AM or PM |

#### Return value

The formatted time.

---

## AfxShortDate

Returns the current date in short format.

```
FUNCTION AfxShortDate (BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxShortMonthName

Returns the localized short name of the specified month.

```
FUNCTION AfxShortMonthName (BYVAL nMonth AS LONG, BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *nMonth* | Valid values are between 1 and 12. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxSystemDay

Returns the current system day. The valid values are 1 through 31.

```
FUNCTION AfxSystemDay () AS WORD
```

#### Remarks

The system time is expressed in Coordinated Universal Time (UTC).

---

## AfxSystemDayName

Returns the localized name of today.

```
FUNCTION AfxSystemDayName (BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxSystemDayOfWeek

Returns the current day of week. It is a numeric value in the range of 0-6 representing Sunday through Saturday: 0 = Sunday, 1 = Monday, etc.

```
FUNCTION AfxSystemDayOfWeek () AS WORD
```
---

## AfxSystemDayShortName

Returns the localized short name of today.

```
FUNCTION AfxSystemDayShortName (BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxSystemFileTime

Returns the current system time as a FILETIME structure.

```
FUNCTION AfxSystemFileTime () AS FILETIME
```

#### Remarks

The system time is expressed in Coordinated Universal Time (UTC).

---

## AfxSystemHour

Returns the current system hour. The valid values are 0 through 23.

```
FUNCTION AfxSystemHour () AS WORD
```

#### Remarks

The system time is expressed in Coordinated Universal Time (UTC).

---

## AfxSystemMonth

Returns the current system month. The valid values are 1 through 12 (1 = January, etc.).

```
FUNCTION AfxSystemMonth () AS WORD
```

#### Remarks

The system time is expressed in Coordinated Universal Time (UTC).

---

## AfxSystemMonthName

Returns the localized name of today's system month.

```
FUNCTION AfxSystemMonthName (BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxSystemShortMonthName

Returns the localized short name of today's system month.

```
FUNCTION AfxSystemShortMonthName (BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

---

## AfxSystemSystemTime

Returns the current system time as a SYSTEMTIME structure.

```
FUNCTION AfxSystemSystemTime () AS SYSTEMTIME
```

#### Remarks

The system time is expressed in Coordinated Universal Time (UTC).

---

## AfxSystemTimeToTime64

Converts a system time to a \_\_time64_t (LONGLONG).

```
FUNCTION AfxSystemTimeToTime64 (BYREF st AS SYSTEMTIME) AS LONGLONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *st* | A SYSTEMTIME structure. |

#### Remarks

The converted time.

---

## AfxSystemTimeToDateStr

Converts a SYSTEMTIME type to a string containing the date based on the specified mask, e.g. "dd-MM-yyyy".

```
FUNCTION AfxSystemTimeToDateStr (BYREF st AS SYSTEMTIME, BYREF wszMask AS WSTRING, _
   BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *st* | A SYSTEMTIME structure. |
| *wszMask* | A picture string that is used to form the date.<br>The format types "d", and "y" must be lowercase and the letter "M" must be uppercase.<br>For example, to get the date string "Wed, Aug 31 94", the application uses the picture string "ddd', ' MMM dd yy". |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

The following table defines the format types used to represent days.

| Format type | Meaning |
| ----------- | ----------- |
| d | Day of the month as digits without leading zeros for single-digit days. |
| dd | Day of the month as digits with leading zeros for single-digit days. |
| ddd | Abbreviated day of the week, for example, "Mon" in English (United States). |
| dddd | Day of the week. |

The following table defines the format types used to represent months.

| Format type | Meaning |
| ----------- | ----------- |
| M | Month as digits without leading zeros for single-digit months. |
| MM | Month as digits with leading zeros for single-digit months. |
| MMM | Abbreviated month, for example, "Nov" in English (United States). |
| MMMM | Month value, for example, "November" for English (United States), and "Noviembre" for Spanish (Spain). |

The following table defines the format types used to represent years.

| Format type | Meaning |
| ----------- | ----------- |
| y | Year represented only by the last digit. |
| yy | Year represented only by the last two digits. A leading zero is added for single-digit years. |
| yyyy | Year represented by a full four or five digits, depending on the calendar used. Thai Buddhist and Korean calendars have five-digit years. The "yyyy" pattern shows five digits for these two calendars, and four digits for all other supported calendars. Calendars that have single-digit or two-digit years, such as for the Japanese Emperor era, are represented differently. A single-digit year is represented with a leading zero, for example, "03". A two-digit year is represented with two digits, for example, "13". No additional leading zeros are displayed. |
| yyyyy | Behaves identically to "yyyy". |

#### Remarks

The formatted date.

---

## AfxSystemTimeToTimeStr

Converts a SYSTEMTIME type to a string containing the time based on the specified mask, e.g. "hh':'mm':'ss".

```
FUNCTION AfxSystemTimeToTimeStr (BYREF st AS SYSTEMTIME, BYREF wszMask AS WSTRING, _
   BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *st* | A SYSTEMTIME structure. |
| *wszMask* | A picture string that is used to form the time. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

Picture string used to form the time.

| Picture    | Meaning |
| ---------- | ----------- |
| h | Hours with no leading zero for single-digit hours; 12-hour clock |
| hh | Hours with leading zero for single-digit hours; 12-hour clock |
| H | Hours with no leading zero for single-digit hours; 24-hour clock |
| HH | Hours with leading zero for single-digit hours; 24-hour clock |
| m | Minutes with no leading zero for single-digit minutes |
| mm | Minutes with leading zero for single-digit minutes |
| s | Seconds with no leading zero for single-digit seconds |
| ss | Seconds with leading zero for single-digit seconds |
| t | One character time marker string, such as A or P |
| tt | Multi-character time marker string, such as AM or PM |

#### Return value

The formatted time.

---

## AfxSystemTimeToVariantTime

Converts a SYSTEMTIME to a DATE_ (double).

```
FUNCTION AfxSystemTimeToVariantTime (BYREF ST AS SYSTEMTIME) AS DATE_
```

| Parameter  | Description |
| ---------- | ----------- |
| *st* | A SYSTEMTIME structure. |

#### Return value

The date and time in DATE_ format.

---

## AfxSystemYear

Returns the current system year. The valid values are 1601 through 30827.

```
FUNCTION AfxSystemYear () AS WORD
```

#### Remarks

The system time is expressed in Coordinated Universal Time (UTC).

---

## AfxTime64

Returns the time as seconds elapsed since midnight, January 1, 1970.

```
FUNCTION AfxTime64 () AS LONGLONG
```

#### Return value

The current system time as a \_\_time64_t (LONGLONG) value.

#### Remarks

Replacement for \_time64, not available in msvcrt.dll.

---

## AfxTime64ToFileTime

Converts a \_\_time64_t (LONGLONG) value to a FILETIME structure.

```
FUNCTION AfxTime64ToFileTime (BYVAL t64 AS LONGLONG) AS FILETIME
```

| Parameter  | Description |
| ---------- | ----------- |
| *t64* | A \_\_time64_t (LONGLONG) value. The time is represented as seconds elapsed since midnight (00:00:00), January 1, 1970, coordinated universal time (UTC). |

#### Return value

The converted time value as FILETIME structure.

---

## AfxTime64ToSystemTime

Converts a \_\_time64_t (LONGLONG) value to a SYSTEMTIME structure.

```
FUNCTION AfxTime64ToSystemTime (BYVAL t64 AS LONGLONG) AS SYSTEMTIME
```

| Parameter  | Description |
| ---------- | ----------- |
| *t64* | A \_\_time64_t (LONGLONG) value. The time is represented as seconds elapsed since midnight (00:00:00), January 1, 1970, coordinated universal time (UTC). |

#### Return value

The converted time value as SYSTEMTIME structure.

---

## AfxTimeZoneBias

Returns the current bias for local time translation. The bias is the difference between Coordinated Universal Time (UTC) and local time. All translations between UTC and local time are based on the following formula: UTC = local time + bias. Units = minutes.

```
FUNCTION AfxTimeZoneBias () AS LONG
```
---

## AfxTimeZoneDaylightBias

Returns the bias value to be used during local time translations that occur during daylight saving time. This property is ignored if a value for the DaylightDay property is not supplied. The value of this property is added to the Bias property to form the bias used during daylight time. In most time zones, the value of this property is -60. Units = minutes.

```
FUNCTION AfxTimeZoneDaylightBias () AS LONG
```
---

## AfxTimeZoneDaylightDay

Returns the **DaylightDayOfWeek** of the **DaylightMonth** when the transition from standard time to daylight saving time occurs on this operating system.

```
FUNCTION AfxTimeZoneDaylightDay () AS WORD
```

**Example**: If the transition day (**DaylightDayOfWeek**) occurs on a Sunday, then the value "1" indicates the first Sunday of the **DaylightMonth**, "2" indicates the second Sunday, and so on. The value "5" indicates the last **DaylightDayOfWeek** in the month.

---

## AfxTimeZoneDaylightDayOfWeek

Day of the week when the transition from standard time to daylight saving time occurs on an operating system.

```
FUNCTION AfxTimeZoneDaylightDayOfWeek () AS WORD
```

#### Return value

The day of the week when the transition from standard time to daylight saving time occurs on an operating system. 0 = Sunday, 1 = Monday, and so on.

---

## AfxTimeZoneDaylightHour

Hour of the day when the transition from standard time to daylight saving time occurs on an operating system.

```
FUNCTION AfxTimeZoneDaylightHour () AS WORD
```
---

## AfxTimeZoneDaylightMinute

Minute of the **DaylightHour** when the transition from standard time to daylight saving time occurs on an operating system.

```
FUNCTION AfxTimeZoneDaylightMinute () AS WORD
```
---

## AfxTimeZoneDaylightMonth

Month when the transition from standard time to daylight saving time occurs on an operating system.

```
FUNCTION AfxTimeZoneDaylightMonth () AS WORD
```

#### Return value

The month when the transition from standard time to daylight saving time occurs on an operating system. 1 = January, 2 = February, and so on.

---

## AfxTimeZoneId

Returns the time zone identifier.

```
FUNCTION AfxTimeZoneId () AS DWORD
```

#### Return value

| Value       | Description |
| ---------- | ----------- |
| **TIME_ZONE_ID_UNKNOWN** (0) | Daylight saving time is not used in the current time zone, because there are no transition dates or automatic adjustment for daylight saving time is disabled. |
| **TIME_ZONE_ID_STANDARD** (1) | The system is operating in the range covered by the StandardDate member of the TIME_ZONE_INFORMATION structure. |
| **TIME_ZONE_ID_DAYLIGHT** (2) | The system is operating in the range covered by the DaylightDate member of the TIME_ZONE_INFORMATION structure. |

If the function fails for other reasons, such as an out of memory error, it returns **TIME_ZONE_ID_INVALID**. To get extended error information, call **GetLastError**.

---

## AfxTimeZoneDaylightName

Returns a description for daylight saving time. For example, "EST" could indicate Eastern Standard Time. This string can be empty.

```
FUNCTION AfxTimeZoneDaylightName () AS DWSTRING
```
---

## AfxTimeZoneIsDaylightSavingTime

Indicates whether the system is operating in the range covered by the DaylightDate member of the TIME_ZONE_INFORMATION structure.

```
FUNCTION AfxTimeZoneIsDaylightSavingTime () AS BOOLEAN
```

#### Return value

TRUE or FALSE.

---

## AfxTimeZoneIsStandardSavingTime

Indicates whether the system is operating in the range covered by the StandardDate member of the TIME_ZONE_INFORMATION structure.

```
FUNCTION AfxTimeZoneIsStandardSavingTime () AS BOOLEAN
```

#### Return value

TRUE or FALSE.

---

## AfxTimeZoneStandardDay

Returns the **StandardDayOfWeek** of the **StandardMonth** when the transition from daylight saving to standard time occurs on this operating system.

```
FUNCTION AfxTimeZoneStandardDay () AS WORD
```

**Example**: If the transition day (**StandardDayOfWeek**) occurs on a Sunday, then the value "1" indicates the first Sunday of the **StandardMonth**, "2" indicates the second Sunday, and so on. The value "5" indicates the last **StandardDayOfWeek** in the month.

---

## AfxTimeZoneStandardDayOfWeek

Day of the week when the transition from daylight saving time to standard time occurs on an operating system.

```
FUNCTION AfxTimeZoneStandardDayOfWeek () AS WORD
```

#### Return value

The day of the week when the transition from daylight saving time to standard time occurs on an operating system. 0 = Sunday, 1 = Monday, and so on.

---

## AfxTimeZoneStandardHour

Hour of the day when the transition from daylight time saving time to standard time occurs on an operating system.

```
FUNCTION AfxTimeZoneStandardHour () AS WORD
```
---

## AfxTimeZoneStandardMinute

Minute of the **StandardHour** when the transition from standard time to daylight saving time occurs on an operating system.

```
FUNCTION AfxTimeZoneStandardMinute () AS WORD
```
---

## AfxTimeZoneStandardMonth

Month when the transition from daylight saving time to standard time occurs on an operating system.

```
FUNCTION AfxTimeZoneStandardMonth () AS WORD
```

#### Return value

The month when the transition from daylight saving time to standard time occurs on an operating system. 1 = January, 2 = February, and so on.

---

## AfxTimeZoneStandardName

Returns a description for standard time. For example, "EST" could indicate Eastern Standard Time. This string can be empty.

```
FUNCTION AfxTimeZoneStandardName () AS DWSTRING
```
---

## AfxVariantDateTimeToStr

Converts a DATE_ type to a string.

```
FUNCTION AfxVariantDateTimeToStr (BYVAL vbDate AS DATE_, BYVAL lcid AS LCID = LOCALE_USER_DEFAULT, _
   BYVAL dwFlags AS DWORD = 0) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *vbDate* | A variant representation of time. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |
| *dwFlags* | Optional. A value made from one or more flags. The following table shows the flags that can be set for this parameter. |

| Flag       | Description |
| ---------- | ----------- |
| LOCALE_NOUSEROVERRIDE | Uses the system default locale settings, rather than custom locale settings. |
| VAR_CALENDAR_HJRI | If set then the Hijri calendar is used. Otherwise the calendar sent in Control Panel is used. |
| VAR_DATEVALUEONLY | Omits the time portion of a **VT_DATE** and retrieves only the date.<br>Applies to conversions to or from dates.<br>Not used for **ChangeType** and **ChangeTypeEx**. |
| VAR_TIMEVALUEONLY | Omits the date portion of a **VT_DATE** and returns only the time. Applies to conversions to or from dates. Not used for **ChangeType** and **ChangeTypeEx**. |

#### Return value

The formatted date and time.

---

## AfxVariantDateToStr

Converts a DATE_ type to a string containing only the date

```
FUNCTION AfxVariantDateToStr (BYVAL vbDate AS DATE_, BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *vbDate* | A variant representation of time. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

#### Return value

The formatted date.

---

## AfxVariantTimeToStr

Converts a DATE_ type to a string containing only the time.

```
FUNCTION AfxVariantTimeToStr (BYVAL vbDate AS DATE_, BYVAL lcid AS LCID = LOCALE_USER_DEFAULT) AS DWSTRING
```

| Parameter  | Description |
| ---------- | ----------- |
| *vbDate* | A variant representation of time. |
| *lcid* | Optional. The language identifier used for the conversion. Default is LOCALE_USER_DEFAULT. |

#### Return value

The formatted time.

---

## AfxVariantTimeToSystemTime

Converts a DATE_ (double) to a SYSTEMTIME.

```
FUNCTION AfxVariantTimeToSystemTime (BYVAL dt AS DATE_) AS SYSTEMTIME
```

| Parameter  | Description |
| ---------- | ----------- |
| *dt* | The DATE_ value. |

#### Return value

The date and time in SYSTEMTIME format.

---

## AfxWeekNumber

Returns the week number for a given date. The year must be a 4 digit year.

```
FUNCTION AfxWeekNumber (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A day number (1-31). |
| *nMonth* | A month number (1-12). |
| *nYear* | A four digit year. |

---

## AfxWeekOne

Returns the first day of the first week of a year. The year must be a 4 digit year.

```
FUNCTION AfxWeekOne (BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nYear* | A four digit year. |

---

## AfxWeeksInMonth

Returns the number of weeks in the specified month. Will be 4 or 5.

```
FUNCTION AfxWeeksInMonth (BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nMonth* | A month number (1-12). |
| *nYear* | A four digit year. |

---

## AfxWeeksInYear

Returns the number of weeks in the year, where weeks are taken to start on Monday. Will be 52 or 53.

```
FUNCTION AfxWeeksInYear (BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nYear* | A four digit year. |

---

