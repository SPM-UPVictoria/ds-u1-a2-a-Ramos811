#include "../include/Placa.h"
#include <iostream>

int main() {
    std::cout << "========================================================\n";
    std::cout << "  SIMULACION DE CAMPO ELECTRICO EN UNA PLACA 10x10\n";
    std::cout << "  Estructura de Datos - Unidad 1 - Actividad 2\n";
    std::cout << "========================================================\n";

    // Crear una placa usando tipo double para mayor precisión
    Placa<double> placa(9.0);  // k = 9.0

    // Agregar cargas puntuales a la placa
    // Formato: Carga(posX, posY, valor_q)
    std::cout << "\n[AGREGANDO CARGAS PUNTUALES]\n";
    
    Carga carga1(2, 2, 5.0);    // Carga positiva en (2, 2)
    std::cout << "  - Carga 1: Pos(" << carga1.getPosX() << ", " << carga1.getPosY() 
              << "), q=" << carga1.getQ() << "\n";
    placa.agregarCarga(carga1);

    Carga carga2(7, 7, -3.0);   // Carga negativa en (7, 7)
    std::cout << "  - Carga 2: Pos(" << carga2.getPosX() << ", " << carga2.getPosY() 
              << "), q=" << carga2.getQ() << "\n";
    placa.agregarCarga(carga2);

    Carga carga3(2, 7, 4.0);    // Carga positiva en (2, 7)
    std::cout << "  - Carga 3: Pos(" << carga3.getPosX() << ", " << carga3.getPosY() 
              << "), q=" << carga3.getQ() << "\n";
    placa.agregarCarga(carga3);

    // Calcular el campo eléctrico en toda la placa
    std::cout << "\n[CALCULANDO CAMPOS ELECTRICOS]\n";
    placa.calcularCampo();
    std::cout << "  Cálculo completado.\n";

    // Mostrar la matriz resultante
    placa.imprimirMatriz();

    // Demostración de plantillas con diferentes tipos numéricos
    std::cout << "========================================================\n";
    std::cout << "  DEMOSTRACION DE PLANTILLAS CON DIFERENTES TIPOS\n";
    std::cout << "========================================================\n\n";

    // Ejemplo con tipo float
    Placa<float> placaFloat(9.0f);
    placaFloat.agregarCarga(Carga(5, 5, 10.0));
    placaFloat.agregarCarga(Carga(5, 5, -5.0));
    placaFloat.calcularCampo();
    std::cout << "Placa con tipo FLOAT creada exitosamente.\n";
    std::cout << "Valor en posición (5,5): " << placaFloat.obtenerValor(5, 5) << "\n\n";

    // Ejemplo con tipo int
    Placa<int> placaInt(9);
    placaInt.agregarCarga(Carga(0, 0, 20.0));
    placaInt.calcularCampo();
    std::cout << "Placa con tipo INT creada exitosamente.\n";
    std::cout << "Valor en posición (1,1): " << placaInt.obtenerValor(1, 1) << "\n\n";

    std::cout << "========================================================\n";
    std::cout << "  PROGRAMA FINALIZADO EXITOSAMENTE\n";
    std::cout << "========================================================\n";

    return 0;
}
