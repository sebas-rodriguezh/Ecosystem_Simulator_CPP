#include "Carnivoro.h"

Carnivoro::Carnivoro(int xAux, int yAux, int ed, int nEnergia) :
	Criatura(xAux, yAux, ed, nEnergia)
{

}
string Carnivoro::tipo() {
	return "Carnivoro";
}