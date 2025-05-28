
#include "AlimentacionH.h"
#include "Criatura.h"
#include "Recurso.h"
#include "Planta.h"

#include <iostream>
using namespace std;

void AlimentacionH::alimentar(Criatura* c, Recurso* r) {
    Planta* planta = dynamic_cast<Planta*>(r);
    if (planta != nullptr) {
        int energia = planta->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);
        cout << "[Alimentacion] Herbivoro comio planta y gano " << energia << " de energia\n";
    }
    else {
        cout << "[Alimentacion] No hay planta para comer\n";
    }
}
