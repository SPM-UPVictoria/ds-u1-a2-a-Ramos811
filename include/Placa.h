#ifndef PLACA_H
#define PLACA_H

#include "Carga.h"
#include <vector>
#include <iostream>
#include <iomanip>

/** @brief Tamaño de la placa (10x10) */
const int TAMANIO_PLACA = 10;

/**
 * @class Placa
 * @brief Clase que representa una placa metálica con cargas puntuales
 * @tparam T Tipo numérico para almacenar valores del campo eléctrico
 */
template<typename T>
class Placa {
private:
    T matriz[TAMANIO_PLACA][TAMANIO_PLACA];  ///< Matriz estática 10x10
    std::vector<Carga> cargas;                ///< Vector de cargas puntuales
    T constante_k;                            ///< Constante de Coulomb

public:
    /**
     * @brief Constructor de la clase Placa
     * @param k Valor de la constante de Coulomb (por defecto 9.0)
     */
    Placa(T k = 9.0);

    /**
     * @brief Agrega una carga puntual a la placa
     * @param carga Objeto Carga a agregar
     */
    void agregarCarga(const Carga& carga);

    /**
     * @brief Calcula el campo eléctrico en toda la placa
     */
    void calcularCampo();

    /**
     * @brief Imprime la matriz del campo eléctrico en formato tabular
     */
    void imprimirMatriz() const;

    /**
     * @brief Obtiene el valor del campo en una posición específica
     * @param i Índice fila
     * @param j Índice columna
     * @return Valor del campo eléctrico
     */
    T obtenerValor(int i, int j) const;

private:
    /**
     * @brief Inicializa la matriz con ceros
     */
    void inicializarMatriz();
};

// Implementación de los métodos template
template<typename T>
Placa<T>::Placa(T k) : constante_k(k) {
    inicializarMatriz();
}

template<typename T>
void Placa<T>::inicializarMatriz() {
    for (int i = 0; i < TAMANIO_PLACA; ++i) {
        for (int j = 0; j < TAMANIO_PLACA; ++j) {
            matriz[i][j] = 0;
        }
    }
}

template<typename T>
void Placa<T>::agregarCarga(const Carga& carga) {
    cargas.push_back(carga);
}

template<typename T>
void Placa<T>::calcularCampo() {
    // Recorre cada celda de la placa
    for (int i = 0; i < TAMANIO_PLACA; ++i) {
        for (int j = 0; j < TAMANIO_PLACA; ++j) {
            T campoTotal = 0;

            // Suma el aporte de cada carga
            for (const auto& carga : cargas) {
                double distancia = carga.calcularDistancia(j, i);
                T aporteCampo = calcularCampoElectrico<T>(
                    constante_k, 
                    static_cast<T>(carga.getQ()), 
                    static_cast<T>(distancia)
                );
                campoTotal += aporteCampo;
            }

            matriz[i][j] = campoTotal;
        }
    }
}

template<typename T>
void Placa<T>::imprimirMatriz() const {
    std::cout << "\n┌────────────────────────────────────────────────────────────────────────────────────────────┐\n";
    std::cout << "│                    MATRIZ DE CAMPO ELECTRICO (10x10)                                   │\n";
    std::cout << "└────────────────────────────────────────────────────────────────────────────────────────────┘\n\n";

    std::cout << std::setw(5) << " " << "|";
    for (int j = 0; j < TAMANIO_PLACA; ++j) {
        std::cout << std::setw(10) << "Col" << j;
    }
    std::cout << "\n";
    std::cout << std::string(5, '-') << "+";
    std::cout << std::string(10 * TAMANIO_PLACA + TAMANIO_PLACA - 1, '-') << "\n";

    for (int i = 0; i < TAMANIO_PLACA; ++i) {
        std::cout << "Row" << std::setw(2) << i << "|";
        for (int j = 0; j < TAMANIO_PLACA; ++j) {
            std::cout << std::setprecision(3) << std::setw(9) << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

template<typename T>
T Placa<T>::obtenerValor(int i, int j) const {
    if (i >= 0 && i < TAMANIO_PLACA && j >= 0 && j < TAMANIO_PLACA) {
        return matriz[i][j];
    }
    return 0;
}

#endif // PLACA_H
