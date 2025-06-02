
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

        if (c->getNivelDeEnergia() >= 100) {
            c->setNivelDeEnergia(100);
        }


        cout << "[Alimentacion] Herbivoro comio planta y gano " << energia << " de energia\n";
        cout << "Ahora el nivel de energia de la criatura es " << c->getNivelDeEnergia() << endl;
    }
    else {
        cout << "[Alimentacion] No hay planta para comer\n";
    }
}

bool AlimentacionH::puedeConsumir(Criatura* criatura, Recurso* recurso) {
    return (recurso->tipo() == "Planta");
}