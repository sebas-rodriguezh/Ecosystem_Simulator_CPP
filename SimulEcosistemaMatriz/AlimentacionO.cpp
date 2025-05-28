#include "AlimentacionO.h"
#include "Entorno.h"
#include "Criatura.h"
#include "Planta.h"
#include "Carne.h"

void AlimentacionO::alimentar(Criatura* c) {
    Entorno* entorno = Entorno::getInstancia();
    int x = c->getX();
    int y = c->getY();
    //hago un casteo dinamico para ver si en la posicion de elemnto hay una planta y asi el animal pueda comer
    Elemento* elemento = entorno->getElemento(x, y);
    if (Planta* planta = dynamic_cast<Planta*>(elemento)) {
        int energia = planta->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);
        planta->consumir(energia);
        entorno->eliminarElemento(x, y);
        cout << "[Alimentación] Omnívoro comió planta y ganó " << energia << " de energía\n";
    }
    //hago un casteo dinamico para ver si en la posicion de elemnto hay carne y asi el animal pueda comer
    else if (Carne* carne = dynamic_cast<Carne*>(elemento)) {
        int energia = carne->getEnergiaDisponible();
        c->setNivelDeEnergia(c->getNivelDeEnergia() + energia);
        carne->consumir(energia);
        entorno->eliminarElemento(x, y);
        cout << "[Alimentación] Omnívoro comió carne y ganó " << energia << " de energía\n";
    }
    else {
        cout << "[Alimentación] No hay alimento adecuado para el omnívoro\n";
    }
}