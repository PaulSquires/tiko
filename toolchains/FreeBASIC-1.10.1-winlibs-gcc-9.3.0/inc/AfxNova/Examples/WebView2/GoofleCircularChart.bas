' ########################################################################################
' Microsoft Windows
' File: Google circular chart.bas
' Contents: WebView2 example
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2026 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define _WIN32_WINNT &h0602
#include once "AfxNova/CWindow.inc"
#define _CWV2_DEBUG_ 1
#include once "AfxNova/CWebView2.inc"
USING AfxNova

DECLARE FUNCTION wWinMain (BYVAL hInstance AS HINSTANCE, _
                           BYVAL hPrevInstance AS HINSTANCE, _
                           BYVAL pwszCmdLine AS WSTRING PTR, _
                           BYVAL nCmdShow AS LONG) AS LONG
   END wWinMain(GetModuleHandleW(NULL), NULL, wCommand(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

CONST IDC_LABEL = 1001

' ========================================================================================
' Build a script for Google circular chart
' ========================================================================================
FUNCTION BuildScript () AS DWSTRING
   DIM s AS DWSTRING
   s  = "<!DOCTYPE html>"
   s += "<html>"
   s += "  <head>"
   s += "    <meta charset='UTF-8'>"
   s += "    <!--Load the AJAX API-->"

   s += "    <script type=""text/javascript"" src=""https://www.gstatic.com/charts/loader.js""></script>"
   s += "    <script type=""text/javascript"">"

   s += "      // Load the Visualization API and the corechart package." & CHR(13, 10)
   s += "      google.charts.load('current', {'packages':['corechart']});"

   s += "      // Set a callback to run when the Google Visualization API is loaded." & CHR(13, 10)
   s += "      google.charts.setOnLoadCallback(drawChart);"

   s += "      // Callback that creates and populates a data table,"
   s += "      // instantiates the pie chart, passes in the data and"
   s += "      // draws it." & CHR(13, 10)
   s += "      function drawChart() {"

   s += "        // Create the data table." & CHR(13, 10)
   s += "        var data = new google.visualization.DataTable();"
   s += "        data.addColumn('string', 'Topping');"
   s += "        data.addColumn('number', 'Slices');"
   s += "        data.addRows(["
   s += "          ['Mushrooms', 3],"
   s += "          ['Onions', 1],"
   s += "          ['Olives', 1],"
   s += "          ['Zucchini', 1],"
   s += "          ['Pepperoni', 2]"
   s += "        ]);"

   s += "        // Set chart options" & CHR(13, 10)
   s += "        var options = {'title':'How Much Pizza I Ate Last Night',"
   s += "                       'width':580,"
   s += "                       'height':380, is3D:true};"

   s += "        // Instantiate and draw our chart, passing in some options." & CHR(13, 10)
   s += "        var chart = new google.visualization.PieChart(document.getElementById('chart_div'));"
   s += "        chart.draw(data, options);"
   s += "      }"
   s += "    </script>"
   s += "  </head>"

   s += "  <body>"
   s += "    <!--Div that will hold the pie chart-->" & CHR(13, 10)
   s += "    <div id='chart_div'></div>"
   s += "  </body>"
   s += "</html>"
   RETURN s
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

   ' // Create the main window
   DIM pWindow AS CWindow
   DIM hWin AS HWND = pWindow.Create(NULL, "WebView2 - Google circular chart", @WndProc)
   ' // Set its client size
   pWindow.SetClientSize(640, 450)
   ' // Center the window
   pWindow.Center

   ' // Adds a label to be used as the host of the WebView2 control
   DIM hLabel AS HWND = pWindow.AddControl("Label", hWin, IDC_LABEL, "", 20, 20, 600, 410)
   ' // Anchors the label to the height and width of the main window
   pWindow.AnchorControl(hLabel, AFX_ANCHOR_HEIGHT_WIDTH)

   ' // Save the script as a temporary file
   DIM dwsTempFile AS DWSTRING = AfxSaveTempHtmlFile(BuildScript)
   ' // Path to navigate to the temporary file
   DIM dwsPath AS DWSTRING = "file:///" & dwsTempFile
   
   ' // Use the same folder for the WebView2 files
   ' // Here we are using a subfolder in the temporary folder
   DIM dwsUserDataFolder AS DWSTRING = AfxGetTempPath & "AfxNovaWebView2"
   ' // Create an instance of WebView
   DIM pWebView2 AS CWebView2 = CWebView2(hLabel, dwsUserDataFolder)
   ' // Wait until is ready
   IF pWebView2.IsReady THEN
      ' // Navigate to the web page
      pWebView2.Navigate(dwsPath)
      ' // Set the focus in the web page
      pWebView2.MoveFocus(COREWEBVIEW2_MOVE_FOCUS_REASON_PROGRAMMATIC)
   END IF

   ' // Dispatch Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

   ' // Delete the temporary file
   AfxDeleteFile(dwsTempFile)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window callback procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   STATIC hFocus AS HWND

   SELECT CASE uMsg

      ' // If an application processes this message, it should return zero to continue
      ' // creation of the window. If the application returns -1, the window is destroyed
      ' // and the CreateWindowExW function returns a NULL handle.
      CASE WM_CREATE
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      ' // Theme has changed
      CASE WM_THEMECHANGED
         AfxEnableDarkModeForWindow(hwnd)
         RETURN 0

      CASE WM_COMMAND
         
         SELECT CASE CBCTL(wParam, lParam)
            ' // If ESC key pressed, close the application sending an WM_CLOSE message
            CASE IDCANCEL
               IF CBCTLMSG(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE WM_SIZE
         ' // Set the bound of the WebView2 control
         DIM hLabel AS HWND = GetDlgItem(hwnd, IDC_LABEL)
         DIM pWebView2 AS CWebView2 PTR = CAST(CWebView2 PTR, GetWindowLongPtrW(hLabel, GWLP_USERDATA))
         IF pWebView2 THEN
            DIM rc AS RECT
            IF GetClientRect(hLabel, @rc) THEN
               pWebView2->SetBounds(rc)
            ENDIF
         END IF

    	CASE WM_DESTROY
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ===================================================================================