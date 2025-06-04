
#pragma once
#include "EstrategiaAlimentacion.h"

class AlimentacionO : public EstrategiaAlimentacion {
public:
    string alimentar(Criatura* c,Recurso* r) override;
    bool puedeConsumir(Criatura* criatura, Recurso* recurso) override;
};
