
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


    //Criatura* omnivoro2 = f.crear("Omnivoro", 5, 6); 
    //Criatura* omnivoro3 = f.crear("Omnivoro", 6, 5); 



    //Elemento* recurso1Planta = new Planta(4, 0, 13);
    //Elemento* recurso2Planta = new Planta(4, 7, 13);
    //Elemento* recurso3Planta = new Planta(7, 7, 13);
    //Elemento* recurso12Carne = new Carne(5, 3,17); 
    //Elemento* recurso22Carne = new Carne(5, 7,17); 
    //Elemento* recurso32Carne = new Carne(6, 4,17); 

    //Elemento* plantaOm = new Planta(0, 2, 13);
    //Elemento* CarneOn = new Carne(2, 1, 17);


    //entorno->agregarElemento(omnivoro3);
    //entorno->agregarElemento(omnivoro2);
    //entorno->agregarElemento(plantaOm);
    //entorno->agregarElemento(CarneOn);

    //entorno->agregarElemento(recurso1Planta);
    //entorno->agregarElemento(recurso12Carne);
    //entorno->agregarElemento(recurso22Carne);
    //entorno->agregarElemento(recurso32Carne);
    //entorno->agregarElemento(recurso2Planta);
    //entorno->agregarElemento(recurso3Planta);

    //int i = 0;
    //while (true) {
    //    cout << "\nIteracion: " << i << endl;
    //    entorno->imprimir();

    //    // Mover la criatura una sola vez por iteración usando moverCriaturaV2
    //    bool sigueViva = entorno->moverCriaturaV2(omnivoro2, true); // true para generar recurso al morir

    //    cout << "\nDespues de mover mi criatura:" << endl;
    //    entorno->imprimir();

    //    if (!sigueViva) {
    //        cout << "La criatura ha muerto. Fin de simulacion." << endl;
    //        omnivoro2 = nullptr; // Importante!
    //        break;
    //    }

    //    cout << "\nInformacion del Carnivoro:" << endl;
    //    cout << "Edad: " << omnivoro2->getEdad()
    //        << " - Energia: " << omnivoro2->getNivelDeEnergia() << endl;

    //    i++;
    //}


    entorno->llenarAleatoriamente();

    // Obtener criaturas existentes en el entorno
    int maxIteraciones = 50;
    for (int i = 0; i < maxIteraciones; ++i) {
        auto criaturas = entorno->obtenerSTLCriaturas();  // 5. Obtener lista fresca cada iteración

        if (criaturas.empty()) {
            cout << "No hay mas criaturas vivas. Simulacion terminada." << endl;
            break;
        }

        cout << "\n--- Iteracion " << i << " ---" << endl;
        entorno->imprimir();

        // 6. Usar remove_if para mayor claridad
        criaturas.erase(remove_if(criaturas.begin(), criaturas.end(),
            [entorno](Criatura* c) {
                return !entorno->moverCriaturaV2(c, true);
            }),
            criaturas.end());

        cout << "\nDespues de mover:" << endl;
        entorno->imprimir();
        cout << "Criaturas vivas: " << criaturas.size() << endl;
    }


    return 0;
}
