#include "FabricaCriaturas.h"
#include <cstdlib>  // para rand()

//este metodo crea las criaturas normal y le setea sus debidas estrategias 
Criatura* FabricaCriaturas::crear(const string& tipo, int x, int y) {
    if (tipo == "Herbivoro") {
        Criatura* c = new Herbivoro(x, y);
        c->setEstrategias(
            new MovimientoAleatorio(),
            new AlimentacionH(),
            new ReproduccionSimple()
        );
        return c;
    }
    else if (tipo == "Carnivoro") {
        Criatura* c = new Carnivoro(x, y);
        c->setEstrategias(
            new MovimientoAleatorio(),
            new AlimentacionC(),
            new ReproduccionSimple()
        );
        return c;
    }
    else if (tipo == "Omnivoro") {
        Criatura* c = new Omnivoro(x, y);
        c->setEstrategias(
            new MovimientoAleatorio(),
            new AlimentacionO(),
            new ReproduccionSimple()
        );
        return c;
    }
    return nullptr;
}

Criatura* FabricaCriaturas::crearAleatorio(int x, int y) {
    int tipo = rand() % 3; // 0=Herbivoro, 1=Carnivoro, 2=Omnivoro
    if (tipo == 0) return crear("Herbivoro", x, y);
    else if (tipo == 1) return crear("Carnivoro", x, y);
    else if (tipo == 2) return crear("Omnivoro", x, y);
    else return nullptr;
}