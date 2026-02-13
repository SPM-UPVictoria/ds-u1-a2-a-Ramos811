#!/bin/bash
# Script de compilación para Linux/Mac con g++

echo "================================================"
echo "Compilando el proyecto de Campo Electrico"
echo "================================================"

# Crear carpeta de compilación si no existe
mkdir -p build

# Compilar el proyecto
g++ -std=c++17 -o build/simulacion src/main.cpp src/Carga.cpp -I include

if [ $? -eq 0 ]; then
    echo ""
    echo "================================================"
    echo "Compilacion exitosa!"
    echo "El ejecutable está en: build/simulacion"
    echo "================================================"
else
    echo ""
    echo "Error durante la compilacion!"
    exit 1
fi
