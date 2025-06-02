
#include "AlimentacionC.h"
#include "Criatura.h"
#include "Carne.h"

void AlimentacionC::alimentar(Criatura* c, Recurso* r) {
    Carne* carne = dynamic_cast<Carne*>(r);
    if (carne != nullptr) {
        int energia = carne->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);

        if (c->getNivelDeEnergia() >= 100) {
            c->setNivelDeEnergia(100);
        }

        cout << "[Alimentacion] Carnivoro comio carne y gano " << energia << " de energia\n";
        cout << "Ahora el nivel de energia de la criatura es " << c->getNivelDeEnergia() << endl;
    }
    else {
        cout << "[Alimentacion] No hay carne para comer\n";
    }
}

bool AlimentacionC::puedeConsumir(Criatura* criatura, Recurso* recurso) {
    return (recurso->tipo() == "X");
}