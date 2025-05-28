
#include "AlimentacionH.h"
#include "Criatura.h"
#include "Recurso.h"
#include "Entorno.h"
#include "Planta.h"

#include <iostream>
using namespace std;

void AlimentacionH::alimentar(Criatura* c) {
    Entorno* entorno = Entorno::getInstancia();
    int x = c->getX();
    int y = c->getY();


    //hago un casteo dinamico para ver si en la posicion de elemnto hay una planta y asi el animal pueda comer
    Elemento* elemento = entorno->getElemento(x, y);
    if (Planta* planta = dynamic_cast<Planta*>(elemento)) {
        int energia = planta->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);
        planta->consumir(energia);
        entorno->eliminarElemento(x, y); // Planta desaparece
        cout << "[Alimentación] Herbívoro comió planta y ganó " << energia << " de energía\n";
    }
    else {
        cout << "[Alimentación] No hay planta para comer\n";
    }
}
