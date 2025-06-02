#pragma once
#include "Criatura.h"

class Omnivoro : public Criatura
{
public:
	Omnivoro(int xAux, int yAux, int ed = 1, int nEnergia = 75);
	string tipo() override;
};