
#pragma once
#include "EstrategiaAlimentacion.h"

class AlimentacionO : public EstrategiaAlimentacion {
public:
    void alimentar(Criatura* c,Recurso* r) override;
};
