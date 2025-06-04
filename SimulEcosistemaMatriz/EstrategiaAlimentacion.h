#pragma once
#include "Recurso.h"
//se declaran para q nop haya dependencia mutua
class Criatura;
class Entorno;

class EstrategiaAlimentacion
{
public:
	virtual string alimentar(Criatura* c, Recurso* r) = 0;
	virtual bool puedeConsumir(Criatura* criatura, Recurso* recurso) = 0;
	virtual ~EstrategiaAlimentacion() {}
};