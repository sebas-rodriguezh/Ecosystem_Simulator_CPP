#pragma once
#include "Elemento.h"
#include "FabricaCriaturas.h"
#include "Planta.h"
#include "Carne.h"
#include <string>

class FabricaElemento {
public:
    // Crear un elemento aleatorio (criatura o recurso)
    static Elemento* crearAleatorio(int x, int y);
    static Elemento* crearRecursoAleatorio(int x, int y);
    static Elemento* crearCriaturaAleatorio(int x, int y);
};