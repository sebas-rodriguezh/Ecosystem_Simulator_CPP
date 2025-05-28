#pragma once

class Criatura;
class Entorno;

class EstrategiaReproduccion
{
public:
    virtual Criatura* reproducir(Criatura* c) = 0;
    virtual ~EstrategiaReproduccion() {}

};