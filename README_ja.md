# mkexe.exe
[English](https://github.com/kirin123kirin/mkexe/blob/main/README.md)

## 概要
Windowsコマンドラインをexe化する。
コマンドプロンプト上で実行可能なコマンドは全て作成できる。
* ワンライナーに限る。複数行にわたるスクリプトのような内容を登録することは不可
* 制限事項もコマンドプロンプトの制約に同じ。
* コマンド文字上限は8191まで等々

## 使用方法

### 例 exe化
```powershell
# Example1.
mkexe.exe "echo foo bar"
# Example2.
mkexe.exe "start http://example.com"
# Example3.
mkexe.exe "cd C:\temp" "echo hoge > hoge.txt" "notepad.exe hoge.txt"
```

### 実行例
```powershell
# Example1.
.\RenameMe.exe #-> foo bar
# Example2.
.\RenameMe.exe #-> open default browser http://example.com
# Example3.
.\RenameMe.exe #-> C:\temp\hoge.txt & open notepad hoge.txt
```

## mkexe.exeのビルド方法
もしリビルドしたければ手順例は以下のとおり。

### ビルドに必要な環境
[clang++](https://github.com/llvm/llvm-project/releases) or [Visual Studio(cl.exe Environment)](https://visualstudio.microsoft.com/ja/downloads/)


### 一番簡単な例
```powershell
make.bat
```

### Clangでのコンパイル例
```powershell
clang++ 01_mkexe_template.cpp
clang++ -o b.exe 02_convert_arraydata.cpp
.\b.exe
clang++ -o mkexe.exe 03_mkexe.cpp
```

### Visual Studio(cl.exe)でのコンパイル例
```powershell
cl 01_mkexe_template.cpp
cl /o b.exe 02_convert_arraydata.cpp
.\b.exe
cl /o mkexe.exe 03_mkexe.cpp
```

## ライセンス
[MIT Liscense]()
