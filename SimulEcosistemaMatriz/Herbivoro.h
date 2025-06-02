#pragma once
#include "Criatura.h"

class Herbivoro : public Criatura
{
public:
	Herbivoro(int xAux, int yAux, int ed = 1, int nEnergia = 75);
	string tipo() override;
	string toString();
};