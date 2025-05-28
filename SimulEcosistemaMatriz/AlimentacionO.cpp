#include "AlimentacionO.h"
#include "Criatura.h"
#include "Planta.h"
#include "Carne.h"

void AlimentacionO::alimentar(Criatura* c,Recurso* r) {
    Planta* planta = dynamic_cast<Planta*>(r);
    if (planta != nullptr) {
        int energia = planta->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);
        cout << "[Alimentacion] Omnivoro comio planta y gano " << energia << " de energia\n";
        return;
    }

    Carne* carne = dynamic_cast<Carne*>(r);
    if (carne != nullptr) {
        int energia = carne->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);
        cout << "[Alimentacion] Omnivoro comio carne y gano " << energia << " de energia\n";
        return;
    }

    cout << "[Alimentacion] Omnivoro no encontro alimento valido\n";
}