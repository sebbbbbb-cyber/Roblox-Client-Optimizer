@echo off

:: IF UR READING THIS USE THE .CMD INSTALLER BECAUSE .BAT IS OLD AS FUCK AND IT DOES SAME THING!!!


::::::::::::::::::::::::::::::::::::::::::::
:: Elevate.cmd - Version 4
:: Automatically check & get admin rights
:: see "https://stackoverflow.com/a/12264592/1016343" for description
::::::::::::::::::::::::::::::::::::::::::::
 CLS
 ECHO.
 ECHO =============================
 ECHO Running Admin shell
 ECHO =============================

:init
 setlocal DisableDelayedExpansion
 set cmdInvoke=1
 set winSysFolder=System32
 set "batchPath=%~0"
 for %%k in (%0) do set batchName=%%~nk
 set "vbsGetPrivileges=%temp%\OEgetPriv_%batchName%.vbs"
 setlocal EnableDelayedExpansion

:checkPrivileges
  NET FILE 1>NUL 2>NUL
  if '%errorlevel%' == '0' ( goto gotPrivileges ) else ( goto getPrivileges )

:getPrivileges
  if '%1'=='ELEV' (echo ELEV & shift /1 & goto gotPrivileges)
  ECHO.
  ECHO **************************************
  ECHO Invoking UAC for Privilege Escalation
  ECHO **************************************

  ECHO Set UAC = CreateObject^("Shell.Application"^) > "%vbsGetPrivileges%"
  ECHO args = "ELEV " >> "%vbsGetPrivileges%"
  ECHO For Each strArg in WScript.Arguments >> "%vbsGetPrivileges%"
  ECHO args = args ^& strArg ^& " "  >> "%vbsGetPrivileges%"
  ECHO Next >> "%vbsGetPrivileges%"

  if '%cmdInvoke%'=='1' goto InvokeCmd 

  ECHO UAC.ShellExecute "!batchPath!", args, "", "runas", 1 >> "%vbsGetPrivileges%"
  goto ExecElevation

:InvokeCmd
  ECHO args = "/c """ + "!batchPath!" + """ " + args >> "%vbsGetPrivileges%"
  ECHO UAC.ShellExecute "%SystemRoot%\%winSysFolder%\cmd.exe", args, "", "runas", 1 >> "%vbsGetPrivileges%"

:ExecElevation
 "%SystemRoot%\%winSysFolder%\WScript.exe" "%vbsGetPrivileges%" %*
 exit /B

:gotPrivileges
 setlocal & cd /d %~dp0
 if '%1'=='ELEV' (del "%vbsGetPrivileges%" 1>nul 2>nul  &  shift /1)

 ::::::::::::::::::::::::::::
 ::START
 ::::::::::::::::::::::::::::
cls
title Roblox Client Optimizer (RCO) Installer...

echo Welcome to RCO Installer!!! ^| (By installing this you agree to all licenses in the licenses folder)
echo Press any key to start the installation!

echo.
pause

echo.
echo Installing VCRedist...
deps\VC_redist.x64.exe /install /quiet /norestart
mkdir %appdata%\RClientOptimizer
echo Done! ^| Copying files to %appdata%\RClientOptimizer\
copy deps\curl.exe %appdata%\RClientOptimizer\
copy deps\animegirl.ico %appdata%\RClientOptimizer\
mkdir "C:\Program Files\RCO"
copy deps\RCO.exe "C:\Program Files\RCO\"
echo.
echo.
echo RCO has now been installed!!
echo If you didn't have any version VCRedist installed beforehand you should restart your PC before running RCO...
echo Press any key to run RCO...
echo.
pause
cls
"C:\Program Files\RCO\RCO.exe"