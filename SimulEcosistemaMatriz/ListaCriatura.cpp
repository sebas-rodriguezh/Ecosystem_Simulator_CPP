#include "ListaCriatura.h"

ListaCriatura::ListaCriatura() {
	primero = NULL;
	actual = NULL;
}

void ListaCriatura::insertar(Criatura* c) {
	actual = new NodoCriatura(c, NULL);
	if (primero == NULL) {
		primero = actual;
	}
	else {
		actual->setSig(primero);
		primero = actual;
	}
}

void ListaCriatura::eliminar(Criatura* c) {
    NodoCriatura* anterior = nullptr; 
    NodoCriatura* actual = primero;

    while (actual != nullptr) {
        if (actual->getCriatura() == c) {
            if (anterior == nullptr) {
                // Es el primer nodo
                primero = actual->getSig();
            }
            else {
                // Salta el nodo actual
                anterior->setSig(actual->getSig());
            }

            delete actual->getCriatura(); 
            delete actual;              
            return;
        }

        anterior = actual;
        actual = actual->getSig();
    }
}
ListaCriatura::~ListaCriatura() {
    while (primero != NULL) {
        actual = primero;
        primero = primero->getSig();
        delete actual;
    }

}
