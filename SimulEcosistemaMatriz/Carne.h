#pragma once
#include "Recurso.h"
class Carne : public Recurso
{
public:
	Carne(int x = 0, int y = 0, int energia = 50);
	string tipo() override;

};