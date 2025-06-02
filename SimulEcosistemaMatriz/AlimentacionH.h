#pragma once
#include "EstrategiaAlimentacion.h"

class AlimentacionH : public EstrategiaAlimentacion {
public:
    void alimentar(Criatura* c, Recurso* r) override;
    bool puedeConsumir(Criatura* criatura, Recurso* recurso) override;
};