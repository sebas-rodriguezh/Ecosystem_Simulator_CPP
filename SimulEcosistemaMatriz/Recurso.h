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

    virtual string tipo()=0; // retorna tipo recurso

};