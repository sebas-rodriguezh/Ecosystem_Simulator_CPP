#include "FabricaElemento.h"
#include <cstdlib>  // para rand()


Elemento* FabricaElemento::crearAleatorio(int x, int y) {
    int tipoElemento = rand() % 5; // 0..2 son criaturas, 3 y 4 recursos

    if (tipoElemento <= 2) {
        // reutilizo la función 
        return FabricaCriaturas::crearAleatorio(x, y);
    }
    else if (tipoElemento == 3) {
        return new Planta(x, y, 50);
    }
    else {
        return new Carne(x, y, 100);
    }
}

Elemento* FabricaElemento::crearRecursoAleatorio(int x, int y) {
    int tipo = rand() % 2;

    if (tipo == 0) {
        return new Planta(x, y, 50);
    }
    else {
        return new Carne(x, y, 100);
    }
}

Elemento* FabricaElemento::crearCriaturaAleatorio(int x, int y) {
    int tipo = rand() % 2;
    return FabricaCriaturas::crearAleatorio(x, y);
}