@echo off
setlocal enabledelayedexpansion
for /f "delims=" %%i in ('dir /s/b *.*') do
(
    set "foo=%%~nxi"
    set foo=!foo: =!
    set foo=!foo: =!
    ren "%%~fi" "!foo!"
)
for /f "delims=" %%i in ('dir /a-d /b *.*') do
(
	echo %%i%% >> size.txt
	echo %%~zi >> size.txt
)
echo end >> size.txt
process.exe
type result.txt
echo.
pause
del result.txt
del size.txt