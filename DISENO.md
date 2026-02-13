# Documentación de Diseño - Simulación de Campo Eléctrico

## 1. Descripción General del Proyecto

El proyecto simula el comportamiento del campo eléctrico en una placa metálica rectangular (matriz 10×10) cuando hay cargas puntuales presentes. La implementación utiliza principios de Programación Orientada a Objetos, plantillas de C++ y cálculos matemáticos.

## 2. Arquitectura del Sistema

### 2.1 Componentes Principales

```
┌─────────────────────────────────────────────┐
│         Simulación de Campo Eléctrico       │
├─────────────────────────────────────────────┤
│                                             │
│  ┌──────────────────────────────────────┐   │
│  │  Clase Carga                         │   │
│  │  - Atributos: posX, posY, q          │   │
│  │  - Métodos: getters, calcularDistancia│  │
│  └──────────────────────────────────────┘   │
│                                             │
│  ┌──────────────────────────────────────┐   │
│  │  Template Placa<T>                   │   │
│  │  - Matriz estática 10×10             │   │
│  │  - Vector de cargas                  │   │
│  │  - Métodos: calcularCampo()          │   │
│  │             imprimirMatriz()         │   │
│  └──────────────────────────────────────┘   │
│                                             │
│  ┌──────────────────────────────────────┐   │
│  │  Template calcularCampoElectrico<T>  │   │
│  │  - Formula: E = k × q / d²           │   │
│  └──────────────────────────────────────┘   │
│                                             │
└─────────────────────────────────────────────┘
```

## 3. Diseño Orientado a Objetos

### 3.1 Clase Carga

**Responsabilidades:**
- Almacenar la posición (x, y) de una carga
- Almacenar el valor de la carga (q)
- Calcular la distancia euclidiana a un punto

**Atributos Privados:**
```cpp
private:
    double posX;    // Posición X
    double posY;    // Posición Y
    double q;       // Valor de la carga
```

**Métodos Públicos:**
- `Carga(double x, double y, double carga)` - Constructor
- `getPosX()` - Obtener posición X
- `getPosY()` - Obtener posición Y
- `getQ()` - Obtener valor de carga
- `calcularDistancia(double x, double y)` - Distancia euclidiana

**Encapsulación:**
Los atributos son privados (principio de encapsulación), y se accede a través de métodos getter.

### 3.2 Clase Placa (Template)

**Responsabilidades:**
- Mantener una matriz estática 10×10 de valores del campo
- Almacenar colección de cargas
- Calcular el campo eléctrico para cada celda
- Mostrar resultados

**Parámetro Template:**
```cpp
template<typename T>
class Placa
```
Permite usar `int`, `float`, o `double` (o cualquier tipo numérico).

**Atributos:**
```cpp
private:
    T matriz[TAMANIO_PLACA][TAMANIO_PLACA];  // Matriz 10×10
    std::vector<Carga> cargas;                // Colección de cargas
    T constante_k;                            // Constante de Coulomb
```

**Métodos Principales:**
- `Placa(T k)` - Constructor con constante k
- `agregarCarga(const Carga& carga)` - Agregar carga a la placa
- `calcularCampo()` - Calcular campo en toda la matriz
- `imprimirMatriz()` - Mostrar matriz en consola
- `obtenerValor(int i, int j)` - Acceder a valor específico

## 4. Implementación de Plantillas

### 4.1 Función Template para Campo Eléctrico

```cpp
template<typename T>
T calcularCampoElectrico(T k, T q, T d) {
    if (d == 0) return 0;  // Prevenir división por cero
    return (k * q) / (d * d);
}
```

**Ventajas:**
- Reutilizable para diferentes tipos numéricos
- Compilación en tiempo de compilación (sin overhead runtime)
- Type-safe

### 4.2 Proceso de Cálculo

Para cada celda de la matriz:

1. **Inicializar**: Campo total = 0
2. **Iterar sobre cada carga**:
   - Calcular distancia euclidiana: $d = \sqrt{(x_{celda} - x_{carga})^2 + (y_{celda} - y_{carga})^2}$
   - Calcular aporte: $E_{aporte} = k \times q / d^2$
   - Sumar al total: $E_{total} += E_{aporte}$
3. **Almacenar** en la matriz

```cpp
void Placa<T>::calcularCampo() {
    for (int i = 0; i < TAMANIO_PLACA; ++i) {
        for (int j = 0; j < TAMANIO_PLACA; ++j) {
            T campoTotal = 0;
            
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
```

## 5. Fórmulas Matemáticas

### 5.1 Distancia Euclidiana

$$d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$$

**Implementación:**
```cpp
double Carga::calcularDistancia(double x, double y) const {
    double deltaX = x - posX;
    double deltaY = y - posY;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}
```

### 5.2 Campo Eléctrico de Coulomb

$$E = k \times \frac{q}{d^2}$$

Donde:
- **k** = 9.0 (constante simplificada)
- **q** = carga puntual
- **d** = distancia

**Característica importante:**
- Si la carga es positiva (q > 0), el campo es positivo (repulsivo)
- Si la carga es negativa (q < 0), el campo es negativo (atractivo)

## 6. Ventajas del Diseño

### 6.1 Encapsulación
- Las propiedades de Carga están protegidas
- Interfaz clara y controlada

### 6.2 Reutilización
- Las plantillas permiten usar diferentes tipos numéricos
- El mismo código funciona para int, float, double, etc.

### 6.3 Mantenibilidad
- Código modular y bien organizado
- Separación de responsabilidades
- Comentarios y documentación clara

### 6.4 Eficiencia
- Matriz estática: acceso O(1)
- Cálculos vectoriales eficientes
- Templates: zero-overhead abstraction

## 7. Casos de Uso

### 7.1 Cargas Opuestas
Crea un patrón simétrico donde el campo es intermedio entre las cargas.

### 7.2 Cargas Misma Polaridad
Crean un patrón repulsivo con máximo entre ellas.

### 7.3 Carga Única
Muestra el patrón de disminución 1/d² caracteristico.

### 7.4 Múltiples Cargas
Demuestra la superposición de campos eléctricos.

## 8. Limitaciones y Consideraciones

1. **Matriz Estática**: Tamaño fijo 10×10, no escalable dinámicamente
2. **Precisión numérica**: Depende del tipo T elegido
3. **Distancia cero**: Se previene división por cero
4. **Representación 2D**: Simplificación del problema 3D real

## 9. Posibles Mejoras Futuras

1. Matriz dinámica o configurable
2. Visualización gráfica 3D
3. Animación de cargas en movimiento
4. Cálculo del potencial eléctrico
5. Integración paralela usando OpenMP

## 10. Referencias Matemáticas

- **Ley de Coulomb**: F = k|q₁||q₂|/r²
- **Campo Eléctrico**: E = F/q = k|q|/r²
- **Principio de Superposición**: Campo total = suma de campos individuales
- **Geometría Euclidiana**: Distancia en 2D

---

**Documento preparado para Estructura de Datos - Unidad 1 - Actividad 2**
