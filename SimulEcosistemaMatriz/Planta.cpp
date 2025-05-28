#include "Planta.h"

Planta::Planta(int x, int y, int energia)
    : Recurso(x, y, energia) {
}
string Planta::tipo() {
    return"Planta";
}