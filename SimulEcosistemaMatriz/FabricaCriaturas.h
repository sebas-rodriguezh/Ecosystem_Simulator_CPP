#pragma once
#include <string>
#include "Criatura.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include "Omnivoro.h"

#include "MovimientoAleatorio.h"
#include "AlimentacionH.h"
#include "AlimentacionC.h"
#include "AlimentacionO.h"
#include "ReproduccionSimple.h"

class FabricaCriaturas {
public:
    static Criatura* crear(const string& tipo, int x, int y);
    static Criatura* crearAleatorio(int x, int y);
};