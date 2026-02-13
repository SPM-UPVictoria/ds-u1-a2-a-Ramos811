#include "../include/Carga.h"
#include <cmath>

Carga::Carga(double x, double y, double carga) 
    : posX(x), posY(y), q(carga) {
}

double Carga::getPosX() const {
    return posX;
}

double Carga::getPosY() const {
    return posY;
}

double Carga::getQ() const {
    return q;
}

double Carga::calcularDistancia(double x, double y) const {
    double deltaX = x - posX;
    double deltaY = y - posY;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}
