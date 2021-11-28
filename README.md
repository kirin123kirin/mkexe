# mkexe.exe
[日本語](https://github.com/kirin123kirin/mkexe/blob/main/README_ja.md)

## Overview
Everything you can do with Windows Command Prompt can be converted to exe.
Wrapper Windows Command to standalone execute file.


## Usage Example

### Build Executable File Example
```powershell
# Example1.
mkexe.exe "echo foo bar"
# Example2.
mkexe.exe "start http://example.com"
# Example3.
mkexe.exe "cd C:\temp" "echo hoge > hoge.txt" "notepad.exe hoge.txt"
```

### Run Example
```powershell
# Example1.
.\RenameMe.exe #-> foo bar
# Example2.
.\RenameMe.exe #-> open default browser http://example.com
# Example3.
.\RenameMe.exe #-> C:\temp\hoge.txt & open notepad hoge.txt
```

## How to Build of mkexe.exe
If you need own build mkexe.exe...


### build require
[clang++](https://github.com/llvm/llvm-project/releases) , [Visual Studio(cl.exe Environment)](https://visualstudio.microsoft.com/ja/downloads/)


### easy method
```powershell
make.bat
```

### C Compile(Clang)
```powershell
clang++ -O2 01_mkexe_template.cpp
clang++ -O2 -o b.exe 02_convert_arraydata.cpp
.\b.exe
clang++ -O2 -o mkexe.exe 03_mkexe.cpp
```

### C Compile(Visual Studio(cl.exe))
```powershell
cl /Ox 01_mkexe_template.cpp
cl /Ox /o b.exe 02_convert_arraydata.cpp
.\b.exe
cl /Ox /o mkexe.exe 03_mkexe.cpp
```

## Liscense
MIT Liscense
