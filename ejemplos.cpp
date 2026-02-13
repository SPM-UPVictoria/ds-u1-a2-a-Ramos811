/*
 * ARCHIVO DE EJEMPLOS Y PRUEBAS
 * 
 * Este archivo contiene ejemplos de cómo usar las clases Carga y Placa
 * Puede compilarse como alternativa a main.cpp para ver diferentes escenarios
 */

#include "include/Placa.h"
#include <iostream>

// Ejemplo 1: Placa con dos cargas opuestas
void ejemplo1_cargas_opuestas() {
    std::cout << "\n=== EJEMPLO 1: Cargas Opuestas ===\n";
    Placa<double> placa(9.0);
    
    placa.agregarCarga(Carga(4, 5, 10.0));   // Carga positiva
    placa.agregarCarga(Carga(5, 5, -10.0));  // Carga negativa
    
    placa.calcularCampo();
    placa.imprimirMatriz();
}

// Ejemplo 2: Tres cargas formando un triángulo
void ejemplo2_cargas_triangulo() {
    std::cout << "\n=== EJEMPLO 2: Cargas en Triángulo ===\n";
    Placa<double> placa(9.0);
    
    placa.agregarCarga(Carga(2, 2, 5.0));    // Vértice inferior izquierdo
    placa.agregarCarga(Carga(8, 2, 5.0));    // Vértice inferior derecho
    placa.agregarCarga(Carga(5, 8, -10.0));  // Vértice superior
    
    placa.calcularCampo();
    placa.imprimirMatriz();
}

// Ejemplo 3: Una sola carga fuerte
void ejemplo3_carga_unica() {
    std::cout << "\n=== EJEMPLO 3: Carga Única Fuerte ===\n";
    Placa<double> placa(9.0);
    
    placa.agregarCarga(Carga(5, 5, 50.0));   // Carga muy fuerte en el centro
    
    placa.calcularCampo();
    placa.imprimirMatriz();
}

// Ejemplo 4: Usando tipo float en lugar de double
void ejemplo4_tipo_float() {
    std::cout << "\n=== EJEMPLO 4: Usando tipo Float ===\n";
    Placa<float> placa(9.0f);
    
    placa.agregarCarga(Carga(3, 3, 8.0));
    placa.agregarCarga(Carga(7, 7, -5.0));
    
    placa.calcularCampo();
    std::cout << "Valor en (5,5) con float: " << placa.obtenerValor(5, 5) << "\n";
}

// Ejemplo 5: Usando tipo int (menor precisión)
void ejemplo5_tipo_int() {
    std::cout << "\n=== EJEMPLO 5: Usando tipo Int (Menor Precisión) ===\n";
    Placa<int> placa(9);
    
    placa.agregarCarga(Carga(4, 4, 30.0));
    placa.agregarCarga(Carga(6, 6, -20.0));
    
    placa.calcularCampo();
    std::cout << "Valor en (5,5) con int: " << placa.obtenerValor(5, 5) << "\n";
}

/*
 * Función main para ejecutar los ejemplos
 * Descomenta los ejemplos que desees ejecutar
 */
int main() {
    std::cout << "======================================\n";
    std::cout << "  EJEMPLOS DE USO - CAMPO ELECTRICO\n";
    std::cout << "======================================\n";
    
    // Descomentar para ejecutar cada ejemplo
    ejemplo1_cargas_opuestas();
    // ejemplo2_cargas_triangulo();
    // ejemplo3_carga_unica();
    // ejemplo4_tipo_float();
    // ejemplo5_tipo_int();
    
    std::cout << "\n======================================\n";
    std::cout << "  FIN DE LOS EJEMPLOS\n";
    std::cout << "======================================\n";
    
    return 0;
}
