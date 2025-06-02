
#include "MovimientoAleatorio.h"
#include "Criatura.h"
#include <cstdlib>  // rand() para numeros aleatorios 

pair<int, int> MovimientoAleatorio::calcularMovimiento(Criatura* c) {
    int dx = (rand() % 3) - 1; // -1, 0, o 1
    int dy = (rand() % 3) - 1;

    int nuevaX = c->getX() + dx;
    int nuevaY = c->getY() + dy;


    return { nuevaX, nuevaY };
}


