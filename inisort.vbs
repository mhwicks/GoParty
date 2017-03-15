'ini file sorter!
'On Error Resume Next

WScript.Echo  "inisort.vbs Active."

Set fso = CreateObject("Scripting.FileSystemObject")

Dim txtTargetFile
Dim txtTargetSection
Dim txtBackupFile
Dim fSource, fTarget
Dim arrSortData()
Dim temp

Initialize()
Backup()
MoveLines()

WScript.Echo  "inisort.vbs Ended normally."

Public Sub Initialize()
	WScript.Echo  "Initializing the ini sort utility."
	Set objArgs = WScript.Arguments
	If objArgs.Count >= 2 Then
		txtTargetFile = objArgs(0)
		txtTargetSection = objArgs(1)
		txtMessage = "Sorting ini file " + txtTargetFile + ", section " + txtTargetSection +  "."
		WScript.Echo txtMessage
	Else 
		WScript.Echo "Format: inisort <ini filename> <section to be sorted>"
		WScript.Quit
	End if
End Sub

Public Sub Backup()
	If fso.FileExists(txtTargetFile) Then
		txtBackupFile = txtTargetFile + ".bak"
		If fso.FileExists(txtBackupFile) Then
			fso.DeleteFile txtBackupFile
		End If
		fso.MoveFile txtTargetFile, txtBackupFile
		If Err.Number > 0 Then
			WScript.Echo "ERROR: " & Err.Number & ", " & Err.Description 
		End If
		WScript.Echo "Backed up .ini file."
	Else
		WScript.Echo "File " + txtTargetFile + " not found.  Please verify that it is fully qualified."
	End If
End Sub

Public Sub MoveLines()
	If fso.FileExists( txtBackupFile ) Then 
		Set fSource = fso.OpenTextFile( txtBackupFile, 1, False)
		Set fTarget = fso.OpenTextFile( txtTargetFile, 2, True)
		Do While fSource.AtEndOfStream = False
			line = fSource.ReadLine
			If line = "[" & txtTargetSection & "]" Then
				WScript.Echo "Found section "+ txtTargetSection + "."
				'Write the header to the target file:
				fTarget.WriteLine(line)
				
				'Read in the entire section as the array:
				i=0
				Do While i < 10000
					i = i + 1				
					line = fSource.ReadLine
					If line = "" Or left(line, 1) = "[" or fSource.AtEndOfStream Then Exit Do
					ReDim Preserve arrSortData(i)
					arrSortData(i) = line
					'WScript.Echo arrSortData(i)
				Loop

				'Sort the array:
				WScript.Echo "Sorting " & UBound(arrSortData) & " item(s)."
				for i = UBound(arrSortData) - 1 To 0 Step -1
				    for j= 0 to i
				        If ucase(arrSortData(j)) > ucase(arrSortData(j+1)) Then
				            temp = arrSortData(j+1)
				            arrSortData(j+1) = arrSortData(j)
				            arrSortData(j) = temp
				        end If
				    Next
				next 

				'Write the array back to the target file:
				For i = 1 To UBound(arrSortData)
					'WScript.Echo arrSortData(i)
					fTarget.WriteLine(arrSortData(i))
				Next
				WScript.Echo "Wrote " & UBound(arrSortData) & " sorted item(s) back to " & txtTargetFile & "."
				
				'set a blank line for writing:
				line = ""
			End if
			fTarget.WriteLine(line)
		Loop
		
		fSource.Close
		fTarget.Close
	End If
End Sub

Function OldCode()
Set fso = CreateObject("Scripting.FileSystemObject")
set WshShell = WScript.CreateObject("WScript.Shell")

'Prepare File Handles:
'----------------------------------------------------------
Const ForReading = 1, ForWriting = 2, ForAppending = 8
Dim fso, fSQL, fINI

'Prepare SQL Connection:
'----------------------------------------------------------
Set oADO = CreateObject("ADODB.Connection")

WScript.Echo  "Waiting for new Work File."

'Keep looping through this entire section:
Do While 1 = 1

	MyFile =  "\\djo-2\MQ2$\Macros\magego.ini"
	'MyFile =  "\\djo-4\MQ2$\Macros\magego.ini"
	WorkFile =  "\\djowebs1\www$\eq\magego\magego.ini"
	
	WScript.Sleep 1000
	'WScript.Echo  "Loop"

	'Check for Magego.ini and act upon it:
	'----------------------------------------------------------
	If fso.FileExists(MyFile) Then
		WScript.Echo  "Found MQ2 work file."
		WScript.Sleep 1000
	
		If fso.FileExists(WorkFile) Then
			WScript.Echo  "Secondary deletion of local work file (This is generally a bad thing)."
	
			Err.Clear
			fso.DeleteFile(WorkFile)
			If Err.Number > 0 Then
				WScript.Echo "ERROR: " & Err.Number & ", " & Err.Description 
			End If

		End If
	
		Err.Clear
		fso.MoveFile MyFile, WorkFile
		If Err.Number > 0 Then
			WScript.Echo "ERROR: " & Err.Number & ", " & Err.Description 
		End If
		WScript.Echo  "Copied work file local."

		MyFile = WorkFile
		
		'MsgBox MyFile
		
		'Open SQL Connection:
		'----------------------------------------------------------
		oADO.Open "Driver={SQL Server};Server=djowebs1;Database=eq;Uid=sa;Pwd=b@nd1d;"
	
		'Read through the data file:
		For i = 1 To 2000
			'Read INI File:
			strMobName = ""
			strMobName = ReadIni(MyFile, i, "MobName")
			If strMobName <> "" Then
				'MyMessage = StrCat(MyMessage, i, ": ", strMobName, @CRLF)
	
				'Read Entire INI File:
				strMobCleanName = ReadIni(MyFile, i, "MobCleanName")
				intIterations = ReadIni(MyFile, i, "Iterations")
				intSeconds = ReadIni(MyFile, i, "Seconds")
				intWaypoint = ReadIni(MyFile, i, "Waypoint")
				intMana = ReadIni(MyFile, i, "Mana")
				fltXP = ReadIni(MyFile, i, "XP")
				fltAAXP = ReadIni(MyFile, i, "AA")
				fltTotalXP = ReadIni(MyFile, i, "Total XP")
				fltTotalAAXP = ReadIni(MyFile, i, "Total AA")
				fltRuntime = ReadIni(MyFile, i, "Total Minutes")
				intKillNo = i
	
				'Update Records:
				SQL = "INSERT INTO MageGo "
				SQL = SQL + "(MobName, "
				SQL = SQL + "MobCleanName, "
				SQL = SQL + "Iterations, "
				SQL = SQL + "Seconds, "
				SQL = SQL + "Waypoint, "
				SQL = SQL + "Mana, "
				SQL = SQL + "XP, "
				SQL = SQL + "AAXP, "
				SQL = SQL + "TotalXP, "
				SQL = SQL + "TotalAAXP, "
				SQL = SQL + "Runtime, "
				SQL = SQL + "KillNo, "
				SQL = SQL + "MageTime) "
	
				SQL = SQL + "VALUES ('" & strMobName
				SQL = SQL + "','" & strMobCleanName
				SQL = SQL + "','" & intIterations
				SQL = SQL + "','" & intSeconds
				SQL = SQL + "','" & intWaypoint
				SQL = SQL + "','" & intMana
				SQL = SQL + "','" & fltXP
				SQL = SQL + "','" & fltAAXP
				SQL = SQL + "','" & fltTotalXP
				SQL = SQL + "','" & fltTotalAAXP
				SQL = SQL + "','" & fltRuntime
				SQL = SQL + "','" & intKillNo
				SQL = SQL + "','" & Now()
				SQL = SQL + "')"
	
				'Execute the SQL Command:
				Set oRS = oADO.Execute(SQL)
				'WScript.Echo SQL
				WScript.Echo "Updated Database with " & strMobName & ": " & intKillNo
			End If
		Next
		
		'Delete the work file:
		WScript.Sleep 1000
		WScript.Echo  "Deleting local work file."

		Err.Clear
		fso.DeleteFile(MyFile)
		If Err.Number > 0 Then
			WScript.Echo "ERROR: " & Err.Number & ", " & Err.Description 
		End If

		WScript.Echo  "========================================================"

		WScript.Echo  "Waiting for new work file."
	End If
	
Loop

'Close up shop:
'----------------------------------------------------------
'oRS.Close : Set oRS = Nothing
oADO.Close : Set oADO = Nothing
End Function


'INI File Reading Function:
'==================================================================================================
Function ReadIni( file, section, item ) 
ReadIni = "" 
If fso.FileExists( file ) Then 
  Set fINI = fso.OpenTextFile( file, 1, False) 
  Do While fINI.AtEndOfStream = False 
    line = fINI.ReadLine 
   	If line = "[" & section & "]" Then 
    	line = fINI.ReadLine 
        	Do While Left( line, 1) <> "[" 
          	If InStr( line, item & "=" ) = 1 Then 
            	ReadIni = mid( line, Len( item ) + 2 ) 
            	Exit Do 
          	End If 
	        If fINI.AtEndOfStream Then Exit Do 
            line = fINI.ReadLine 
        Loop 
    Exit Do 
    End If 
  Loop 
  fINI.Close 
End If 
End Function 

