#pragma once

class Criatura;
class Entorno;

class EstrategiaMovimiento
{
public:
	virtual void mover(Criatura* c) = 0;
	virtual ~EstrategiaMovimiento() {}
};