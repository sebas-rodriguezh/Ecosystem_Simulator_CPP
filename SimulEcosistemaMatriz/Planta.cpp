#include "Planta.h"

Planta::Planta(int x, int y, int energiaInicial) : Recurso(x, y, energiaInicial) {}

void Planta::reducirEnergia() {
    consumir(10); // usa metodo de Recurso
}

int Planta::getNivelDeEnergia() const {
    return getEnergiaDisponible(); // usa metodo del recurso
}
string Planta::tipo() {
    return"Planta";
}