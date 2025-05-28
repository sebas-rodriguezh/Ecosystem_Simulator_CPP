#pragma once
#include "Criatura.h"

class Omnivoro : public Criatura
{
public:
	Omnivoro(int xAux = 0, int yAux = 0, int ed = 0, int nEnergia = 75);
	string tipo() override;
};