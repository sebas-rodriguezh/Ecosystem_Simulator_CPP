#pragma once
#include "EstrategiaReproduccion.h" 

class ReproduccionSimple : public EstrategiaReproduccion {
public:
    Criatura* reproducirConLaPareja (Criatura* c1, Criatura* c2) override;
    bool puedeReproducirseCon(Criatura* c1, Criatura* c2) override;
};