@echo off
cls
title Roblox Client Optimizer (RCO) Installer...

echo Welcome to RCO Installer!!! ^| (By installing this you agree to all licenses in the licenses folder)
echo Press any key to start the installation!

echo.
pause

echo.
echo Installing VCRedist...
deps\VC_redist.x64.exe /install /quiet /norestart
mkdir "C:\RClientOptimizer"
echo Done! ^| Copying files to C:\RClientOptimizer\
copy deps\curl.exe "C:\RClientOptimizer\"
copy deps\animegirl.ico "C:\RClientOptimizer\"
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