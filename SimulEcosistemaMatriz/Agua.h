#pragma once
#include "Recurso.h"

class Agua : public Recurso
{
public:
	Agua(int x, int y, int energiaInicial = 50);
	void reducirEnergia() override;
	int getNivelDeEnergia() const override;
	string tipo()override;
	void reducirEnergiaPeroConAguaAlrededor() override;
};

