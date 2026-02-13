cmake_minimum_required(VERSION 3.10)
project(SimulacionCampoElectrico)

# Configuración del estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Directorios de inclusión
include_directories(${CMAKE_SOURCE_DIR}/include)

# Archivos fuente
set(SOURCES
    src/main.cpp
    src/Carga.cpp
)

# Crear el ejecutable
add_executable(simulacion_campo_electrico ${SOURCES})

# Opciones de compilación
if(MSVC)
    target_compile_options(simulacion_campo_electrico PRIVATE /W4)
else()
    target_compile_options(simulacion_campo_electrico PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Mensaje de éxito
message(STATUS "Proyecto configurado exitosamente!")
message(STATUS "Comando de compilación: cmake --build . --config Release")
