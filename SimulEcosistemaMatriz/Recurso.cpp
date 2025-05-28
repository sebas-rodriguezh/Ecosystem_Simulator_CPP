#include "Recurso.h"

Recurso::Recurso(int x, int y, int energia) : Elemento(x, y), energiaDisponible(energia) {};

Recurso::~Recurso() {

}

int Recurso::getEnergiaDisponible() const {
	return energiaDisponible;
}


//revisar
void Recurso::consumir(int cantidad) {
	energiaDisponible -= cantidad;
	if (energiaDisponible < 0) { energiaDisponible = 0; }

}

string Recurso::tipo() {
	return "Recurso";
}