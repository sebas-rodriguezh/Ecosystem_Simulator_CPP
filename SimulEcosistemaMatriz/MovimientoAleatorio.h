
#pragma once
#include "EstrategiaMovimiento.h"
#include "Criatura.h"
#include <cstdlib>//libreria para tirar numeros random
#include "Entorno.h"
#include "Recurso.h"

class MovimientoAleatorio : public EstrategiaMovimiento
{
public:
	void mover(Criatura* c)override;
};
