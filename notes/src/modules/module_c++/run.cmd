@PUSHD %~dp0
@ECHO --------Compiling
@g++ main.cpp -o main.exe
@ECHO --------Runing
@main.exe
@POPD