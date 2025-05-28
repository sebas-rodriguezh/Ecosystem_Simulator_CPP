#include "ReproduccionSimple.h"
#include "Entorno.h"
#include "Criatura.h"
#include "FabricaCriaturas.h" 

Criatura* ReproduccionSimple::reproducir(Criatura* c) {
    if (c->getNivelDeEnergia() < 20) {
        cout << "[Reproducción] Energía insuficiente\n";
        return nullptr;
    }

    Entorno* entorno = Entorno::getInstancia();
    int x = c->getX();
    int y = c->getY();

    // Verificamos si hay otra criatura en la misma casilla 
    Elemento* elem = entorno->getElemento(x, y);
    if (elem != nullptr && elem != c) {
        if (Criatura* pareja = dynamic_cast<Criatura*>(elem)) {
            if (pareja->tipo() == c->tipo()) {
                // Buscar espacio para el hijo
                //chat
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int nx = x + dx;
                        int ny = y + dy;
                        if (entorno->esPosicionValida(nx, ny) && entorno->getElemento(nx, ny) == nullptr) {
                            //preguntar a sebas
                            //cambiarlo
                            Criatura* hijo = FabricaCriaturas::crearAleatorio(nx, ny);
                            if (hijo) {
                                entorno->agregarElemento(hijo);
                                c->setNivelDeEnergia(c->getNivelDeEnergia() / 2);//xq es bebe
                                cout << "[Reproducción] Nueva criatura creada en (" << nx << ", " << ny << ")\n";
                                return hijo;
                            }
                        }
                    }
                }
                cout << "[Reproducción] No hay espacio para el hijo\n";
                return nullptr;
            }
        }
    }

    cout << "[Reproducción] No hay pareja para reproducirse en la misma casilla\n";
    return nullptr;
}