@PUSHD %~dp0
@ECHO --------Compiling
@gcc main.c -o main.exe
@ECHO --------Runing
@main.exe
@POPD