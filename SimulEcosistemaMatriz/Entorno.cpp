#include "Entorno.h"
#include "Entorno.h"
#include "FabricaElemento.h"
#include <iostream>

Entorno* Entorno::instancia = nullptr;

Entorno::Entorno(int filas, int columnas) : filas(filas), columnas(columnas) {
    // Crear matriz dinámica
    //puro legner progra1
    matriz = new Elemento * *[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new Elemento * [columnas];
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = nullptr;
        }
    }
}

Entorno::~Entorno() {
    limpiar();

    // Liberar memoria de matriz dinámica
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

Entorno* Entorno::getInstancia(int filas, int columnas) {
    if (instancia == nullptr) {
        instancia = new Entorno(filas, columnas);
    }
    return instancia;
}

bool Entorno::esPosicionValida(int x, int y) const {
    return x >= 0 && x < filas && y >= 0 && y < columnas;
}

Elemento* Entorno::getElemento(int x, int y) const {
    if (!esPosicionValida(x, y)) return nullptr;
    return matriz[x][y];
}

void Entorno::agregarElemento(Elemento* elem) {
    int x = elem->getX();
    int y = elem->getY();
    if (esPosicionValida(x, y) && matriz[x][y] == nullptr) {
        matriz[x][y] = elem;
    }
    else {
        //excepcion
        cout << "[Entorno] Error al agregar elemento en posición (" << x << ", " << y << ")\n";
    }
}

void Entorno::llenarAleatoriamente() {
    int totalCeldas = filas * columnas;
    int cantidadCriaturas = totalCeldas * 0.10;
    int cantidadRecursos = totalCeldas * 0.10;

    int colocadas = 0;
    while (colocadas < cantidadCriaturas) {
        int x = rand() % filas;
        int y = rand() % columnas;
        if (matriz[x][y] == nullptr) {
            matriz[x][y] = FabricaElemento::crearCriaturaAleatorio(x, y);
            colocadas++;
        }
    }

    colocadas = 0;
    while (colocadas < cantidadRecursos) {
        int x = rand() % filas;
        int y = rand() % columnas;
        if (matriz[x][y] == nullptr) {
            matriz[x][y] = FabricaElemento::crearRecursoAleatorio(x, y);
            colocadas++;
        }
    }
}


void Entorno::eliminarElemento(int x, int y) {
    if (esPosicionValida(x, y) && matriz[x][y] != nullptr) {
        delete matriz[x][y];
        matriz[x][y] = nullptr;
    }
}

void Entorno::moverElemento(int xOrig, int yOrig, int xDest, int yDest) {
    if (!esPosicionValida(xOrig, yOrig) || !esPosicionValida(xDest, yDest)) {
        cout << "[Entorno] Movimiento fuera de rango\n";
        return;
    }
    if (matriz[xOrig][yOrig] == nullptr) {
        cout << "[Entorno] No hay elemento en la posición origen (" << xOrig << ", " << yOrig << ")\n";
        return;
    }
    if (matriz[xDest][yDest] != nullptr) {
        cout << "[Entorno] Posición destino ocupada (" << xDest << ", " << yDest << ")\n";
        return;
    }
    cout << "[Entorno] Moviendo elemento de (" << xOrig << ", " << yOrig << ") a (" << xDest << ", " << yDest << ")\n";
    matriz[xDest][yDest] = matriz[xOrig][yOrig];
    matriz[xOrig][yOrig] = nullptr;
    matriz[xDest][yDest]->setPosicion(xDest, yDest);
}




void Entorno::imprimir() const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] != nullptr) {
                std::cout << matriz[i][j]->tipo()[0] << " ";
            }
            else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

void Entorno::limpiar() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] != nullptr) {
                delete matriz[i][j];
                matriz[i][j] = nullptr;
            }
        }
    }
}