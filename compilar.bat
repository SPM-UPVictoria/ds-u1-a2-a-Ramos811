@echo off
REM Script de compilación para Windows con g++

echo ================================================
echo Compilando el proyecto de Campo Electrico
echo ================================================

REM Crear carpeta de compilación si no existe
if not exist "build" mkdir build

REM Compilar el proyecto
g++ -std=c++17 -o build/simulacion.exe src/main.cpp src/Carga.cpp -I include

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ================================================
    echo Compilacion exitosa!
    echo El ejecutable está en: build/simulacion.exe
    echo ================================================
) else (
    echo.
    echo Error durante la compilacion!
    pause
    exit /b 1
)
