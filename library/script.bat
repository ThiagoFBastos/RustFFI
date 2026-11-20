
@echo off
setlocal

REM Initialize MSVC environment
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
if errorlevel 1 exit /b 1

REM Compile C with MinGW
cl /c /EHsc /std:c11 /arch:SSE2 cmath.c /Focmath.obj
if errorlevel 1 exit /b 1

lib /OUT:libcmath.lib cmath.obj
if errorlevel 1 exit /b 1

REM Compile C++ with MSVC
cl /c /EHsc /std:c++17 fenwick.cpp /Fofenwick.obj
if errorlevel 1 exit /b 1

REM Create static library
lib /OUT:libfenwick.lib fenwick.obj
if errorlevel 1 exit /b 1

echo.
echo Build completed successfully!
