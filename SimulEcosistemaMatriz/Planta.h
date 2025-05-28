#pragma once
#include "Recurso.h"
class Planta : public Recurso
{
public:
	Planta(int x = 0, int y = 0, int energia = 50);
	string tipo()override;
};