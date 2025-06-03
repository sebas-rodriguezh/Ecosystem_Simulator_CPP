#pragma once
#include "Recurso.h"
#include <cstdlib>  // rand() para numeros aleatorios 
class Carne : public Recurso
{
public:
	Carne(int x = 0, int y = 0, int energia = 50);
	void reducirEnergia() override;
	int getNivelDeEnergia() const override;
	string tipo() override;

}; 

	