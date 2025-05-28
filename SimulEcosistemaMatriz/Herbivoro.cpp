#include "Herbivoro.h"


Herbivoro::Herbivoro(int xAux, int yAux, int ed, int nEnergia) :
	Criatura(xAux, yAux, ed, nEnergia)
{

}


string Herbivoro::tipo() {
	return "Herbivoro";
}
//xd no se ocupa
string Herbivoro::toString() {
	stringstream s;
	s << "Tipo de criatura: " << tipo() << endl;
	s << "Coordenada X: " << x << endl;
	s << "Coordenada Y: " << y << endl;
	s << "Edad: " << edad << endl;
	s << "Nivel de Energia: " << nivelDeEnergia << endl;
	return s.str();
}