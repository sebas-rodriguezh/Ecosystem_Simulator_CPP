
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


    entorno->llenarAleatoriamente();

    int maxIteraciones = 50;
    for (int i = 0; i < maxIteraciones; ++i) {
        entorno->limpiarMensajes(); 

        auto criaturas = entorno->obtenerSTLCriaturas();

        if (criaturas.empty()) {
            cout << "No hay mas criaturas vivas. Simulacion terminada." << endl;
            break;
        }

        cout << "\n--- Iteracion " << i << " ---" << endl;
        cout << entorno->imprimir() << endl;

        cout << entorno->degradarRecursos() << endl;

        criaturas.erase(remove_if(criaturas.begin(), criaturas.end(),
            [entorno](Criatura* c) {
                return !entorno->moverCriaturaV2(c, true);
            }),
            criaturas.end());

        cout << "\nEventos en esta iteracion:" << endl;
        for (const auto& msg : entorno->obtenerMensajes()) {
            cout << "> " << msg << endl;
        }

        cout << "\nDespues de mover:" << endl;
        cout << entorno->imprimir() << endl;
        cout << "Criaturas vivas: " << criaturas.size() << endl;
        cout << "Recursos restantes: " << entorno->contarRecursosDisponibles() << endl;
    }


    return 0;
}
