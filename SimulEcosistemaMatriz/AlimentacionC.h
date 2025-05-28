#pragma once
#include "EstrategiaAlimentacion.h"

class AlimentacionC :public EstrategiaAlimentacion {
public:
	void alimentar(Criatura* c, Recurso* r) override;  
};