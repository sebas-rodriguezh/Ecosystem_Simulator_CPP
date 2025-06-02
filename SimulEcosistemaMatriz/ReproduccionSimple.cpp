#include "ReproduccionSimple.h"
#include "Criatura.h"
#include "FabricaCriaturas.h" 

Criatura* ReproduccionSimple::reproducirConLaPareja(Criatura* c1, Criatura* c2) {

	c1->setNivelDeEnergia(c1->getNivelDeEnergia() - 20);
	c2->setNivelDeEnergia(c2->getNivelDeEnergia() - 20);

	if (c1->tipo() == c2->tipo())
	{
		return FabricaCriaturas::crear(c1->tipo(), 0, 0);
	}

	return nullptr;

}


bool ReproduccionSimple::puedeReproducirseCon(Criatura* c1, Criatura* c2) {
	return (c1->tipo() == c2->tipo() &&
		c1->getNivelDeEnergia() > 40 && c2->getNivelDeEnergia() > 40);
}
