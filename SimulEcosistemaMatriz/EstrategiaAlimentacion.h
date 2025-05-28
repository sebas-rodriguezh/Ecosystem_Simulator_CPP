#pragma once

//se declaran para q nop haya dependencia mutua
class Criatura;
class Entorno;

class EstrategiaAlimentacion
{
public:
	virtual void alimentar(Criatura* c) = 0;
	virtual ~EstrategiaAlimentacion() {}
};