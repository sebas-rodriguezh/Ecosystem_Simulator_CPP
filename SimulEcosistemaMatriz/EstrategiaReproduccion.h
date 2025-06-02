#pragma once

class Criatura;


class EstrategiaReproduccion
{
public:
    virtual Criatura* reproducirConLaPareja(Criatura* c1, Criatura* c2) = 0;
    virtual ~EstrategiaReproduccion() {}
    virtual bool puedeReproducirseCon(Criatura* c1, Criatura* c2) = 0;
};