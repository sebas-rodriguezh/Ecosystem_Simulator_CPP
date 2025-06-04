#include "Agua.h"

Agua::Agua(int x, int y, int energia) : Recurso(x, y, energia) {}

void Agua::reducirEnergia()
{
	int valorConsumido = 1;
	consumir(valorConsumido);
}

int Agua::getNivelDeEnergia() const
{
	return getEnergiaDisponible();
}

string Agua::tipo()
{
	return "Agua"; 
}
