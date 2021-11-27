@echo off

clang++ 01_mkexe_template.cpp
clang++ -O2 -o b.exe 02_convert_arraydata.cpp
.\b.exe
clang++ -O2 -o mkexe.exe 03_mkexe.cpp
del a.exe b.exe

REM tests
.\mkexe.exe "echo HOGE"

setlocal
for /f "usebackq delims=" %%A in (`.\RenameMe.exe`) do set result=%%A
if %result%==HOGE (
    echo Test OK.
    del RenameMe.exe
) else (
    echo Test NG.
    exit
)

echo mkexe.exe is Everything you can do with Windows Command Prompt can be converted to exe.
echo but one liner command.
echo Execute file Make Usage Example:
echo mkexe.exe "echo foo bar"
echo mkexe.exe "start http://example.com"
echo mkexe.exe "cd C:\temp" "echo hoge > hoge.txt" "notepad.exe hoge.txt"

echo Run Example.
echo .\RenameMe.exe
echo Enjoy!
