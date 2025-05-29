
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Entorno.h"
#include "FabricaElemento.h"
#include "Criatura.h"
#include "MovimientoAleatorio.h"

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


    Planta* recurso1 = new Planta(0, 0, 50);  
    FabricaCriaturas f; 
    Criatura* herbi = f.crear("Herbivoro", 0, 0); 
   // Herbivoro* herbi = new Herbivoro(0, 0,4, 20); 
    if (Herbivoro* h = dynamic_cast<Herbivoro*>(herbi)) {
        h->alimentar(recurso1);
    }

    //srand(time(nullptr));  // Inicializa el generador de números aleatorios

    // Crear una criatura base (puedes cambiar por Herbivoro/Carnivoro si ya los tenés)
    Carnivoro* criatura = new Carnivoro(5, 5,9,90);  // Posición inicial (5,5)

    // Asignar estrategia de movimiento aleatorio
    criatura->setEstrategias(new MovimientoAleatorio(),nullptr,nullptr);

    // Mostrar posición inicial
    std::cout << "Posición inicial: (" << criatura->getX() << ", " << criatura->getY() << ")\n";

    // Mover la criatura varias veces
    for (int i = 0; i < 5; ++i) {
        std::pair<int, int> nuevaPos = criatura->mover();
        criatura->setX(nuevaPos.first);
        criatura->setY(nuevaPos.second);
        std::cout << "Movimiento " << i + 1 << ": (" << criatura->getX() << ", " << criatura->getY() << ")\n";
    }

    delete criatura;
    return 0;
}
