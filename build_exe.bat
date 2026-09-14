@echo off
REM Builds dist\HandControl.exe (single file, no Python needed to run it)
REM and stages a ready-to-copy folder at dist\HandControl\.
setlocal

if not exist .venv (
    echo Creating virtual environment...
    python -m venv .venv || goto :fail
)

echo Installing dependencies...
.venv\Scripts\python.exe -m pip install -r requirements.txt pyinstaller || goto :fail

echo Building...
.venv\Scripts\python.exe -m PyInstaller --noconfirm --clean HandControl-onefile.spec || goto :fail

echo Staging portable folder...
if not exist dist\HandControl mkdir dist\HandControl
copy /Y dist\HandControl.exe dist\HandControl\ >nul
copy /Y hardware_config.json dist\HandControl\ >nul
if not exist dist\HandControl\pir_recordings mkdir dist\HandControl\pir_recordings
copy /Y pir_recordings\*.json dist\HandControl\pir_recordings\ >nul

echo.
echo Done. Copy the whole dist\HandControl folder to the other machine.
pause
exit /b 0

:fail
echo.
echo BUILD FAILED - see the error above.
pause
exit /b 1
