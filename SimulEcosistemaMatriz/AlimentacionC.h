#pragma once
#include "EstrategiaAlimentacion.h"

class AlimentacionC :public EstrategiaAlimentacion {
public:
	void alimentar(Criatura* c, Recurso* r) override;  
	bool puedeConsumir(Criatura* criatura, Recurso* recurso) override;
};