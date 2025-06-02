#pragma once
#include "Criatura.h"


class Carnivoro : public Criatura
{
public:
	Carnivoro(int xAux, int yAux, int ed = 1, int nEnergia = 75);
	string tipo() override;
};