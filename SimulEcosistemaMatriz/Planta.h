#pragma once
#include "Recurso.h"
#include <cstdlib> 
class Planta : public Recurso
{
public:
	Planta(int x, int y, int energiaInicial = 50);
	void reducirEnergia() override;
	int getNivelDeEnergia() const override;
	string tipo()override;
};