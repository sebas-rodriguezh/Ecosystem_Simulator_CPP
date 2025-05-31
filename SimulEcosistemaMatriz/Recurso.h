#pragma once
#include "Elemento.h"
using namespace std;

class Recurso : public Elemento
{
private:
    int energiaDisponible;// para saber cuanta energia tiene cada aliemento
public:
    Recurso(int x, int y, int energia);
    virtual ~Recurso();

    int getEnergiaDisponible() const;
    void consumir(int cantidad);
    virtual void reducirEnergia() = 0; // Método abstracto
    virtual int getNivelDeEnergia() const = 0;
    virtual string tipo()=0; // retorna tipo recurso

};