
#include "Criatura.h"


Criatura::Criatura(int xAux, int yAux, int ed, int nEnergia)
	: Elemento(xAux, yAux),
	edad(ed),
	nivelDeEnergia(nEnergia),
	estrategiaMovimiento(nullptr),
	estrategiaAlimentacion(nullptr),
	estrategiaReproduccion(nullptr) {
}


Criatura::~Criatura() {

}

void Criatura::setEstrategias(EstrategiaMovimiento* em, EstrategiaAlimentacion* ea, EstrategiaReproduccion* er) {
	estrategiaMovimiento = em;
	estrategiaAlimentacion = ea;
	estrategiaReproduccion = er;
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

string Criatura::alimentar(Recurso* r) {
	if (estrategiaAlimentacion) {
		return estrategiaAlimentacion->alimentar(this, r);
	}
}

pair<int, int> Criatura::mover() {
	if (estrategiaMovimiento) {
		return estrategiaMovimiento->calcularMovimiento(this);
	}
	return { x, y }; // Si no hay estrategia, se queda en la misma posición 
}


Criatura* Criatura::reproducir(Criatura* c1, Criatura* c2) {
	if (estrategiaReproduccion) {
		return estrategiaReproduccion->reproducirConLaPareja(c1, c2);
	}
	return nullptr;
}


void Criatura::setPos(int x, int y) {

	Elemento::setPosicion(x, y);
}

bool Criatura::puedeConsumir(Recurso* recursoConsumir) {
	if (estrategiaAlimentacion == nullptr) return false;
	return estrategiaAlimentacion->puedeConsumir(this, recursoConsumir);
}


bool Criatura::puedeReproducirseCon(Criatura* otraCriatura) {
	if (estrategiaReproduccion == nullptr) return false;
	return estrategiaReproduccion->puedeReproducirseCon(this, otraCriatura);
}



