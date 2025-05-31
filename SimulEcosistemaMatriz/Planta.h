#pragma once
#include "Recurso.h"
class Planta : public Recurso
{
public:
	Planta(int x, int y, int energiaInicial = 40);
	void reducirEnergia() override;
	int getNivelDeEnergia() const override;
	string tipo()override;
};