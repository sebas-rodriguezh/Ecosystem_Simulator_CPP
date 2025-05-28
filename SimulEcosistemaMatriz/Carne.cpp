#include "Carne.h"

Carne::Carne(int x, int y, int energia) : Recurso(x, y, energia) {}

string Carne::tipo() {
	return "X";
}