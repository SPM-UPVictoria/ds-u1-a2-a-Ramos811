# Manual de Instalación y Compilación

## Requisitos del Sistema

- **Compilador C++**: g++ (versión 7.0+), MSVC, o clang
- **C++ Standard**: C++17 o superior
- **Sistema Operativo**: Windows, Linux, o macOS
- **CMake** (opcional): Versión 3.10+

## Verificar Instalación de Compilador

### Windows (MinGW/MSYS2)

```powershell
g++ --version
```

Si no está instalado, descargue e instale:
- **MinGW**: http://www.mingw.org/
- **MSYS2**: https://www.msys2.org/

### Linux

```bash
sudo apt-get install g++ build-essential
g++ --version
```

### macOS

```bash
clang --version
# Si no está instalado, instale Xcode Command Line Tools:
xcode-select --install
```

## Método 1: Compilación Directa con g++

### En Windows

```powershell
cd "tu\ruta\Practica A2"
g++ -std=c++17 -o simulacion.exe src/main.cpp src/Carga.cpp -I include
```

### En Linux/macOS

```bash
cd ~/tu/ruta/Practica A2
g++ -std=c++17 -o simulacion src/main.cpp src/Carga.cpp -I include
```

## Método 2: Usando Script de Compilación

### Windows

```powershell
cd "tu\ruta\Practica A2"
compil ar.bat
```

### Linux/macOS

```bash
cd ~/tu/ruta/Practica A2
bash compilar.sh
```

## Método 3: Usando CMake

### Requisitos
1. Instalar CMake desde https://cmake.org/download/
2. Verificar instalación: `cmake --version`

### En Windows (con Visual Studio)

```powershell
cd "tu\ruta\Practica A2"
cmake -B build -G "Visual Studio 16 2019"
cmake --build build --config Release
```

### En Windows (con MinGW)

```powershell
cd "tu\ruta\Practica A2"
cmake -B build -G "MinGW Makefiles"
cmake --build build
```

### En Linux/macOS

```bash
cd ~/tu/ruta/Practica A2
cmake -B build
cmake --build build
```

## Compilación con Óptimización

Para obtener mejor rendimiento:

```bash
g++ -std=c++17 -O3 -o simulacion src/main.cpp src/Carga.cpp -I include
```

Opciones de optimización:
- `-O0`: Sin optimización (por defecto, más rápido de compilar)
- `-O1`: Optimización básica
- `-O2`: Optimización media
- `-O3`: Máxima optimización (puede aumentar tamaño del ejecutable)

## Compilación con Advertencias

Para ver todas las advertencias y asegurar código limpio:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -o simulacion src/main.cpp src/Carga.cpp -I include
```

Opciones:
- `-Wall`: Advertencias generales
- `-Wextra`: Advertencias adicionales
- `-Wpedantic`: Cumplimiento estricto del estándar C++

## Ejecución del Programa

### Windows

```powershell
# Si compiló en carpeta actual
.\simulacion.exe

# Si compiló en carpeta build
.\build\simulacion.exe
```

### Linux/macOS

```bash
# Si compiló en carpeta actual
./simulacion

# Si compiló en carpeta build
./build/simulacion
```

## Compilación de Ejemplos Alternativos

Para compilar el archivo de ejemplos en lugar de main.cpp:

```bash
g++ -std=c++17 -o ejemplos src/ejemplos.cpp src/Carga.cpp -I include
```

## Troubleshooting

### Error: "g++ no se reconoce"

**Solución Windows:**
- Instale MinGW o MSYS2
- Agregue la ruta de g++ a las variables de entorno del sistema

**Solución Linux:**
```bash
sudo apt-get install build-essential
```

### Error: "Archivo no encontrado"

**Verificar:**
- Esté en el directorio correcto: `cd "Practica A2"`
- Que los archivos existan: `dir` (Windows) o `ls` (Linux/Mac)

### Error de compilación C++

**Soluciones:**
1. Verificar que el compilador soporte C++17:
   ```bash
   g++ --std=c++17 --version
   ```

2. Si el compilador no soporta C++17, intentar con C++14 (menos recomendado):
   ```bash
   g++ -std=c++14 -o simulacion src/main.cpp src/Carga.cpp -I include
   ```

### Error "Project configured with CMake"

Si CMake no está instalado:
- Descargar desde https://cmake.org/download/
- O usar compilación directa con g++

## Verificación de la Instalación

Para verificar que todo funciona:

1. **Compile el proyecto:**
   ```bash
   g++ -std=c++17 -o simulacion src/main.cpp src/Carga.cpp -I include
   ```

2. **Ejecute el programa:**
   ```bash
   ./simulacion (Linux/Mac) o simulacion.exe (Windows)
   ```

3. **Deberá ver:**
   - Cargas siendo agregadas
   - Matriz 10x10 de valores numéricos
   - Demostración de plantillas
   - Mensaje "PROGRAMA FINALIZADO EXITOSAMENTE"

## Estructura de Directorios Esperada

```
Practica A2/
├── include/
│   ├── Carga.h
│   └── Placa.h
├── src/
│   ├── main.cpp
│   ├── Carga.cpp
│   ├── ejemplos.cpp
│   └── (simulacion.exe o ../simulacion después de compilar)
├── build/            (creada después de compilar con CMake)
├── CMakeLists.txt
├── compilar.bat
├── compilar.sh
├── README.md
├── DISENO.md
└── INSTALACION.md (este archivo)
```

## Próximos Pasos

Después de compilar exitosamente:

1. **Explorar el código**: Revise los archivos .h y .cpp
2. **Ejecutar ejemplos**: Modifique main.cpp o ejemplos.cpp
3. **Experimentar con cargas**: Agregue diferentes cargas
4. **Cambiar tipos numéricos**: Use `Placa<int>`, `Placa<float>`, etc.

---

**¿Necesita ayuda?** Revise los archivos README.md y DISENO.md para más información.
