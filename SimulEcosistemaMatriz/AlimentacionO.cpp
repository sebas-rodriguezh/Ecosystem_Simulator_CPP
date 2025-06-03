#include "AlimentacionO.h"
#include "Criatura.h"
#include "Planta.h"
#include "Carne.h"

void AlimentacionO::alimentar(Criatura* c, Recurso* r) {
    Planta* planta = dynamic_cast<Planta*>(r);
    if (planta != nullptr) {
        int energia = planta->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);

        if (c->getNivelDeEnergia() >= 100) {
            c->setNivelDeEnergia(100);
        }

        cout << "[Alimentacion] Omnivoro comio planta y gano " << energia << " de energia\n";
        cout << "Ahora el nivel de energia de la criatura es " << c->getNivelDeEnergia() << endl;
        return;
    }

    Carne* carne = dynamic_cast<Carne*>(r);
    if (carne != nullptr) {
        int energia = carne->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);

        if (c->getNivelDeEnergia() >= 100) {
            c->setNivelDeEnergia(100);
        }


        cout << "[Alimentacion] Omnivoro comio Bistek y gano " << energia << " de energia\n";
        cout << "Ahora el nivel de energia de la criatura es " << c->getNivelDeEnergia() << endl;
        return;
    }

    cout << "[Alimentacion] Omnivoro no encontro alimento valido\n";
}


bool AlimentacionO::puedeConsumir(Criatura* criatura, Recurso* recurso) {
    return (recurso->tipo() == "Planta" || recurso->tipo() == "Bistek");
}