#include "Carne.h"

Carne::Carne(int x, int y, int energia) : Recurso(x, y, energia) {}

void Carne::reducirEnergia() {
    consumir(25);
}

int Carne::getNivelDeEnergia() const {
    return getEnergiaDisponible();
}

string Carne::tipo() {
	return "X";
}