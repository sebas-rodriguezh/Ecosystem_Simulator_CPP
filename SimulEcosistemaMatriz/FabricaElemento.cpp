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
        return new Carne(x, y, 60);
    }
}

Elemento* FabricaElemento::crearRecursoAleatorio(int x, int y) {
    int tipo = rand() % 2;

    if (tipo == 0) {
        return new Planta(x, y, 50);
    }
    else {
        return new Carne(x, y, 60);
    }
}

Elemento* FabricaElemento::crearCriaturaAleatorio(int x, int y) {
    int tipo = rand() % 2;
    return FabricaCriaturas::crearAleatorio(x, y);
}

Elemento* FabricaElemento::crearRecursoDeTipo(string tipo, int x, int y) {
    if (tipo == "Carne") return new Carne(x, y, 30); // Valor energético
    else if (tipo == "Planta") return new Planta(x, y, 20);
    return nullptr;
}