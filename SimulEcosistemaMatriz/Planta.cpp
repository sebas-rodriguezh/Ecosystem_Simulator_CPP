#include "Planta.h"

Planta::Planta(int x, int y, int energiaInicial) : Recurso(x, y, energiaInicial) {}

void Planta::reducirEnergia() {
    int valorConsumido = rand() % 10;
    consumir(valorConsumido);
}

int Planta::getNivelDeEnergia() const {
    return getEnergiaDisponible(); // usa metodo del recurso
}
string Planta::tipo() {
    return "Planta";
}

void Planta::reducirEnergiaPeroConAguaAlrededor() {
    consumir(1); 
}
