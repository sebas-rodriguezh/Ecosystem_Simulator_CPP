
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Entorno.h"
#include "FabricaElemento.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Entorno* entorno = Entorno::getInstancia(10, 10);
    entorno->llenarAleatoriamente();

    std::cout << "Estado inicial del entorno:\n";
    entorno->imprimir();

    // Ejemplo mover un elemento de (0,0) a (1,1) 
    entorno->moverElemento(0, 0, 1, 1);

    std::cout << "\nEstado después de mover elemento de (0,0) a (1,1):\n";
    entorno->imprimir();

    entorno->limpiar();

    return 0;
}
