#pragma once
#include "Elemento.h"
#include "MovimientoAleatorio.h"
#include "AlimentacionH.h"
#include "AlimentacionC.h"
#include "AlimentacionO.h"
#include "ReproduccionSimple.h"

class EstrategiaMovimiento;
class EstrategiaAlimentacion;
class EstrategiaReproduccion;
class Entorno;

class Criatura : public Elemento
{
protected:
	int edad;
	int nivelDeEnergia;
	EstrategiaMovimiento* estrategiaMovimiento;
	EstrategiaAlimentacion* estrategiaAlimentacion;
	EstrategiaReproduccion* estrategiaReproduccion;


public:
	Criatura(int xAux = 0, int yAux = 0, int ed = 0, int nEnergia = 75);
	virtual ~Criatura();

	//sets
	void setEstrategias(EstrategiaMovimiento* em, EstrategiaAlimentacion* ea, EstrategiaReproduccion* er);
	void setEdad(int edAux);
	void setNivelDeEnergia(int nivelEAux);
	//gets
	int getEdad();
	int getNivelDeEnergia();
	//metodos
	void incrementarEdad();

	void alimentar(Recurso* r);
	pair<int, int> mover(); 

	void setPos(int x, int y);

	virtual string tipo()=0;
};