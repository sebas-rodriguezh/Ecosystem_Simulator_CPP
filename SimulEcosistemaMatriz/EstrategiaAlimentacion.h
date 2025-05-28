#pragma once
#include "Recurso.h"
//se declaran para q nop haya dependencia mutua
class Criatura;
class Entorno;

class EstrategiaAlimentacion
{
public:
	virtual void alimentar(Criatura* c, Recurso* r) = 0;
	virtual ~EstrategiaAlimentacion() {}
};