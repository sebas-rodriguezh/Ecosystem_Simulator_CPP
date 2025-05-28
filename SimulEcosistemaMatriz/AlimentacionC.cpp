
#include "AlimentacionC.h"
#include "Entorno.h"
#include "Criatura.h"
#include "Carne.h"

void AlimentacionC::alimentar(Criatura* c) {
    Entorno* entorno = Entorno::getInstancia();
    int x = c->getX();
    int y = c->getY();
    //hago un casteo dinamico para ver si en la posicion de elemnto hay carne y asi el animal pueda comer
    Elemento* elemento = entorno->getElemento(x, y);
    if (Carne* carne = dynamic_cast<Carne*>(elemento)) {
        int energia = carne->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);
        carne->consumir(energia);
        entorno->eliminarElemento(x, y);
        cout << "[Alimentación] Carnívoro comió carne y ganó " << energia << " de energía\n";
    }
    else {
        cout << "[Alimentación] No hay carne para comer\n";
    }
}
