
#include "AlimentacionC.h"
#include "Criatura.h"
#include "Carne.h"

string AlimentacionC::alimentar(Criatura* c, Recurso* r) 
{
    stringstream s; 

    Carne* carne = dynamic_cast<Carne*>(r);
    if (carne != nullptr) {
        int energia = carne->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);

        if (c->getNivelDeEnergia() >= 100) {
            c->setNivelDeEnergia(100);
        }

        s << "[Alimentacion] Carnivoro comio Bistek y gano " << energia << " de energia\n";
        s << "Ahora el nivel de energia de la criatura es " << c->getNivelDeEnergia() << endl;
    }
    else {
        s << "[Alimentacion] No hay carne para comer\n";
    }
    return s.str(); 
}

bool AlimentacionC::puedeConsumir(Criatura* criatura, Recurso* recurso) {
    return (recurso->tipo() == "Bistek");
}