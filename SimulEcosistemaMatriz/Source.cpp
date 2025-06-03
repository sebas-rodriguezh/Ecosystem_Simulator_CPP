
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Entorno.h"
#include "FabricaElemento.h"
#include "Criatura.h"
#include "MovimientoAleatorio.h"


int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Entorno* entorno = Entorno::getInstancia(10, 10);
    FabricaCriaturas f;

    entorno->iniciarSimulacionHastaQueTodasLasCriaturasMueran(); 

    return 0;
}
