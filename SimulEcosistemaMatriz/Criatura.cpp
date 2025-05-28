
#include "Criatura.h"


Criatura::Criatura(int xAux, int yAux, int ed, int nEnergia)
	:Elemento(xAux, yAux), edad(ed), nivelDeEnergia(nEnergia),
	estrategiaMovimiento(nullptr), estrategiaAlimentacion(nullptr), estrategiaReproduccion(nullptr) {
}


Criatura::~Criatura() {

}

void Criatura::setEstrategias(EstrategiaMovimiento* em, EstrategiaAlimentacion* ea, EstrategiaReproduccion* er) {
	estrategiaMovimiento = em;
	estrategiaAlimentacion = ea;
	estrategiaReproduccion = er;
}

void Criatura::actuar() {

	if (estrategiaMovimiento)
		estrategiaMovimiento->mover(this);
	if (estrategiaAlimentacion)
		estrategiaAlimentacion->alimentar(this);
	if (estrategiaReproduccion)
		estrategiaReproduccion->reproducir(this);

	incrementarEdad();
}

void Criatura::incrementarEdad() {
	edad++;
}

void Criatura::setEdad(int edAux) {
	this->edad = edAux;
}


void Criatura::setNivelDeEnergia(int nivelEAux) {
	this->nivelDeEnergia = nivelEAux;
}


int Criatura::getEdad() {
	return edad;
}

int Criatura::getNivelDeEnergia() {
	return nivelDeEnergia;
}

void Criatura::setPos(int x, int y) {

	Elemento::setPosicion(x, y);
}

string Criatura::tipo() {
	return "Criatura";
}
