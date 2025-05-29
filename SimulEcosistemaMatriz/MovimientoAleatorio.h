
#pragma once
#include "EstrategiaMovimiento.h"

class MovimientoAleatorio : public EstrategiaMovimiento {
public:
    pair<int, int> calcularMovimiento(Criatura* c) override;
};
