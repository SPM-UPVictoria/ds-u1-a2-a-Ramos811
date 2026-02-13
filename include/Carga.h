#ifndef CARGA_H
#define CARGA_H

#include <cmath>

/**
 * @class Carga
 * @brief Clase que representa una carga puntual en el espacio
 */
class Carga {
private:
    double posX;    ///< Posición en el eje X
    double posY;    ///< Posición en el eje Y
    double q;       ///< Valor de la carga (positivo o negativo)

public:
    /**
     * @brief Constructor de la clase Carga
     * @param x Posición en X
     * @param y Posición en Y
     * @param carga Valor de la carga
     */
    Carga(double x, double y, double carga);

    /**
     * @brief Obtiene la posición X de la carga
     * @return Posición X
     */
    double getPosX() const;

    /**
     * @brief Obtiene la posición Y de la carga
     * @return Posición Y
     */
    double getPosY() const;

    /**
     * @brief Obtiene el valor de la carga
     * @return Valor de la carga
     */
    double getQ() const;

    /**
     * @brief Calcula la distancia euclidiana entre la carga y un punto
     * @param x Coordenada X del punto
     * @param y Coordenada Y del punto
     * @return Distancia euclidiana
     */
    double calcularDistancia(double x, double y) const;
};

/**
 * @brief Función template para calcular el campo eléctrico
 * @tparam T Tipo numérico (int, float, double)
 * @param k Constante de Coulomb
 * @param q Carga puntual
 * @param d Distancia desde la carga
 * @return Campo eléctrico calculado
 */
template<typename T>
T calcularCampoElectrico(T k, T q, T d) {
    if (d == 0) return 0;  // Evitar división por cero
    return (k * q) / (d * d);
}

#endif // CARGA_H
