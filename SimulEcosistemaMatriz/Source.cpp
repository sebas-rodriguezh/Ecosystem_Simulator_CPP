#include <thread>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Entorno.h"


void iniciarSimulacion();

int main() {
    iniciarSimulacion(); 
    return 0;
}


void iniciarSimulacion() {
    srand(static_cast<unsigned>(time(nullptr)));
    Entorno* entorno = Entorno::getInstancia(10, 10);


    entorno->llenarAleatoriamente();

    int maxIteraciones = 50;
    for (int i = 0; i < maxIteraciones; ++i) {
        entorno->limpiarMensajes();

        auto criaturas = entorno->obtenerSTLCriaturas();

        if (criaturas.empty()) {
            cout << "No hay mas criaturas vivas. Simulacion terminada." << endl;
            break;
        }

        cout << endl << "--- Iteracion " << i << " ---" << endl;
        cout << entorno->imprimir() << endl;

        cout << entorno->degradarRecursos() << endl;

        criaturas.erase(remove_if(criaturas.begin(), criaturas.end(),
            [entorno](Criatura* c) {
                return !entorno->moverCriaturaV2(c, true);
            }),
            criaturas.end());

        cout << endl << "Eventos en esta iteracion:" << endl;
        for (const auto& msg : entorno->obtenerMensajes()) {
            cout << "> " << msg << endl;
        }

        cout << endl << "Despues de mover:" << endl;
        cout << entorno->imprimir() << endl;
        cout << "Criaturas vivas: " << criaturas.size() << endl;
        cout << "Recursos restantes: " << entorno->contarRecursosDisponibles() << endl;

        this_thread::sleep_for(chrono::seconds(5));

    }

}
