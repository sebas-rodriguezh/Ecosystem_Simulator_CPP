#include "Omnivoro.h"


Omnivoro::Omnivoro(int xAux, int yAux, int ed, int nEnergia) :
	Criatura(xAux, yAux, ed, nEnergia)
{

}
string Omnivoro::tipo() {
	return "Omnivoro";
}