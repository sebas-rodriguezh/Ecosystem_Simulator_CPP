#include "Carne.h"

Carne::Carne(int x, int y, int energia) : Recurso(x, y, energia) {}

void Carne::reducirEnergia() 
{
    int valorConsumido = rand() % 10;
    consumir(valorConsumido);
}

int Carne::getNivelDeEnergia() const {
    return getEnergiaDisponible();
}

string Carne::tipo() {
	return "Bistek";
}