#include "Elemento.h"


Elemento::Elemento(int xAux, int yAux) : x(xAux), y(yAux)
{

}

Elemento::~Elemento() {

}

void Elemento::setX(int xAux) {
	this->x = xAux;
}

void Elemento::setY(int yAux) {
	this->y = yAux;
}

void Elemento::setPosicion(int xNew, int yNew) {
	x = xNew;
	y = yNew;
}


int Elemento::getX() {
	return x;
}

int Elemento::getY() {
	return y;
}