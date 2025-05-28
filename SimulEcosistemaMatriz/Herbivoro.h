#pragma once
#include "Criatura.h"

class Herbivoro : public Criatura
{
public:
	Herbivoro(int xAux = 0, int yAux = 0, int ed = 0, int nEnergia = 75);
	string tipo() override;
	string toString();
};