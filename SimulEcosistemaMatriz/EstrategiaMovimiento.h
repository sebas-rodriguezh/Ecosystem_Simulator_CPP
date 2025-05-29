#pragma once

#include <utility> // para par ordenado 
using namespace std; 
class Criatura;

class EstrategiaMovimiento {
public:
   
    virtual pair<int, int> calcularMovimiento(Criatura* c) = 0;  //para q retorne dos numeros
    virtual ~EstrategiaMovimiento() {}
};