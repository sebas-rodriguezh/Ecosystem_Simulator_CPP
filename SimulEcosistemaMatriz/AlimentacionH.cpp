
#include "AlimentacionH.h"
#include "Criatura.h"
#include "Recurso.h"
#include "Planta.h"
#include "Agua.h"
#include <iostream>
using namespace std;

string AlimentacionH::alimentar(Criatura* c, Recurso* r) 
{
    stringstream s; 
    Agua* agua = dynamic_cast<Agua*>(r);
    Planta* planta = dynamic_cast<Planta*>(r);
    if (planta != nullptr) {
        int energia = planta->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);

        if (c->getNivelDeEnergia() >= 100) {
            c->setNivelDeEnergia(100);
        }


        s << "[Alimentacion] Herbivoro comio planta y gano " << energia << " de energia\n";
        s << "Ahora el nivel de energia de la criatura es " << c->getNivelDeEnergia() << endl;
    }
    else if (agua != nullptr) {
        int energia = agua->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);

        if (c->getNivelDeEnergia() >= 100) {
            c->setNivelDeEnergia(100);
        }

        s << "[Alimentacion] Herbivoro bebio Agua y gano " << energia << " de energia\n";
        s << "Ahora el nivel de energia de la criatura es " << c->getNivelDeEnergia() << endl;
    }
    else {
        s << "[Alimentacion] Recurso no comestible por esta criatura\n";
    }

    return s.str();
}

bool AlimentacionH::puedeConsumir(Criatura* criatura, Recurso* recurso) {
    return (recurso->tipo() == "Planta" || recurso->tipo() == "Agua" );
}