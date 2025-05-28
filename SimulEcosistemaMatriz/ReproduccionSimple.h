#pragma once
#include "EstrategiaReproduccion.h" 

class ReproduccionSimple : public EstrategiaReproduccion {
public:
    Criatura* reproducir(Criatura* c) override;
};