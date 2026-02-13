# Simulación de Campo Eléctrico en una Placa

## 📋 Descripción

Este proyecto implementa una simulación de campo eléctrico en una placa metálica (matriz 10x10) con cargas puntuales. El programa calcula el campo eléctrico resultante en cada punto de la placa usando la fórmula de Coulomb.

## 🎯 Características

- **Clase Carga**: Representa cargas puntuales con posición (x, y) y valor q
- **Plantillas (Templates)**: Soporta múltiples tipos numéricos (int, float, double)
- **Matriz Estática 10x10**: Almacena los valores del campo eléctrico
- **Cálculo de Distancia Euclidiana**: Entre cada celda y las cargas
- **Visualización en Consola**: Matriz tabular con los resultados

## 📂 Estructura del Proyecto

```
Practica A2/
├── include/
│   ├── Carga.h          # Definición de la clase Carga y función template
│   └── Placa.h          # Definición de la clase Placa (template)
├── src/
│   ├── main.cpp         # Programa principal
│   ├── Carga.cpp        # Implementación de la clase Carga
│   └── CMakeLists.txt   # Configuración CMake
├── CMakeLists.txt       # Configuración general del proyecto
├── compilar.bat         # Script de compilación para Windows
├── compilar.sh          # Script de compilación para Linux/Mac
└── README.md            # Este archivo
```

## 🔧 Compilación

### En Windows:
```bash
compilar.bat
```

O usar g++ directamente:
```bash
g++ -std=c++17 -o simulacion.exe src/main.cpp src/Carga.cpp -I include
```

### En Linux/Mac:
```bash
bash compilar.sh
```

O usar g++ directamente:
```bash
g++ -std=c++17 -o simulacion src/main.cpp src/Carga.cpp -I include
```

## 🚀 Ejecución

### Windows:
```bash
simulacion.exe
```

### Linux/Mac:
```bash
./simulacion
```

## 📊 Fórmula Utilizada

Para calcular el campo eléctrico se utiliza:

```
E = k × q / d²
```

Donde:
- **k** = 9.0 (constante de Coulomb simplificada)
- **q** = valor de la carga (positivo o negativo)
- **d** = distancia euclidiana desde la carga al punto

## 💻 Ejemplo de Uso

```cpp
// Crear una placa con tipo double
Placa<double> placa(9.0);

// Agregar cargas puntuales
placa.agregarCarga(Carga(2, 2, 5.0));    // Carga positiva en (2,2)
placa.agregarCarga(Carga(7, 7, -3.0));   // Carga negativa en (7,7)

// Calcular el campo eléctrico
placa.calcularCampo();

// Mostrar la matriz
placa.imprimirMatriz();
```

## 🎓 Conceptos Implementados

1. **Programación Orientada a Objetos (POO)**
   - Encapsulación: Los atributos de Carga son privados
   - Métodos getter para acceso controlado

2. **Plantillas (Templates)**
   - La clase Placa es un template para soportar múltiples tipos
   - La función calcularCampoElectrico es un template

3. **Arreglos Multidimensionales**
   - Matriz estática 2D de tamaño 10×10

4. **Cálculos Matemáticos**
   - Distancia euclidiana: √((x₂-x₁)² + (y₂-y₁)²)
   - Campo eléctrico usando fórmula de Coulomb

## 🧮 Detalles Técnicos

### Clase Carga
- Almacena posición (X, Y) y carga (q)
- Método `calcularDistancia()` para calcular distancia euclidiana
- Getters para acceder a los atributos

### Clase Placa (Template)
- Matriz estática `T matriz[10][10]`
- Vector de cargas
- Método `calcularCampo()` que suma los aportes de todas las cargas
- Método `imprimirMatriz()` para visualización

## 📝 Salida del Programa

El programa muestra:
1. Características de las cargas agregadas
2. Matriz de campo eléctrico en formato tabular
3. Demostración de plantillas con diferentes tipos (float, int)

## ⚙️ Requisitos

- Compilador C++ que soporte C++17 (g++, clang, MSVC)
- CMake (opcional, para alternativa de compilación)

## 📄 Licencia

Proyecto académico para la Estructura de Datos - Unidad 1 - Actividad 2
