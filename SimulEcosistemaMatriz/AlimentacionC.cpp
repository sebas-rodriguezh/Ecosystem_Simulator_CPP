
#include "AlimentacionC.h"
#include "Criatura.h"
#include "Carne.h"

void AlimentacionC::alimentar(Criatura* c,Recurso* r) {
    Carne* carne = dynamic_cast<Carne*>(r);
    if (carne != nullptr) {
        int energia = carne->getEnergiaDisponible(); 
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia); 
        cout << "[Alimentacion] Carnivoro comio carne y gano " << energia << " de energia\n";
    }
    else {
        cout << "[Alimentacion] No hay carne para comer\n";
    }
}