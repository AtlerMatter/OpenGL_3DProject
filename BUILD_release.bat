@echo off
setlocal EnableDelayedExpansion
for /f "delims=" %%a in ('dir /s /b /a-d src\\*.cpp') do set "name=!name! %%a"

for %%I in (.) do set CurrDir=%%~nI%%~xI

for %%I in (.) do set CurrDir=%%~nI%%~xI

call "%PROGRAMFILES%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" 

cl.exe /EHsc /MD /fp:precise /sdl /O2 /GL /Ob2 /Iinclude /Fedebug\\%CurrDir%_debug.exe /Fodebug\\ /Fddebug\\ %name% lib\\*.c /link /MACHINE:X64 lib\\*.lib gdi32.lib user32.lib kernel32.lib shell32.lib

::Commented out compiler options
:: /Zi
:: /nologo 

::pause