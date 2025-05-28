#include "MovimientoAleatorio.h"


//void MovimientoAleatorio::mover(Criatura* c) {
//	Entorno* entorno = Entorno::getInstancia();
//	int x = c->getX();
//	int y = c->getY();
//
//	int dx = (rand() % 3) - 1;//aca en estas dos lineas lo genera random
//	int dy = (rand() % 3) - 1;
//	int nuevoX = x + dx;// se usma porque los numeros random puede ser negativo 
//	int nuevoY = y + dy;//y se puede mover para atras o adelante para eso lo sumamos
//
//	if (entorno->esPosicionValida(nuevoX, nuevoY)) {  //aca verificamos si la nueva pos no se sale de la matriz
//		Elemento* destino = entorno->getElemento(nuevoX, nuevoY);
//
//		if (destino == nullptr) {
//			entorno->moverElemento(x, y, nuevoX, nuevoY);
//			c->setPosicion(nuevoX, nuevoY);
//
//		}
//		else if (Recurso* recurso = dynamic_cast<Recurso*>(destino)) {
//			int energiaConsumida = recurso->getEnergiaDisponible();
//			c->setNivelDeEnergia(c->getNivelDeEnergia() + energiaConsumida);
//			recurso->consumir(energiaConsumida);
//
//			entorno->eliminarElemento(nuevoX, nuevoY);
//			entorno->moverElemento(x, y, nuevoX, nuevoY);
//			c->setPosicion(nuevoX, nuevoY);
//		}
//	}
//	c->setNivelDeEnergia(c->getNivelDeEnergia() - 1); 
//}

void MovimientoAleatorio::mover(Criatura* c) {
    Entorno* entorno = Entorno::getInstancia();
    int x = c->getX();
    int y = c->getY();

    bool seMovio = false;

    for (int intento = 0; intento < 10 && !seMovio; ++intento) {
        int dx = (rand() % 3) - 1; // -1, 0, 1
        int dy = (rand() % 3) - 1;

        int nuevoX = x + dx;
        int nuevoY = y + dy;

        if ((dx != 0 || dy != 0) && entorno->esPosicionValida(nuevoX, nuevoY)) {
            Elemento* destino = entorno->getElemento(nuevoX, nuevoY);

            if (destino == nullptr) {
                entorno->moverElemento(x, y, nuevoX, nuevoY);
                c->setPosicion(nuevoX, nuevoY);
                seMovio = true;
            }
            else if (Recurso* recurso = dynamic_cast<Recurso*>(destino)) {
                int energiaConsumida = recurso->getEnergiaDisponible();
                c->setNivelDeEnergia(c->getNivelDeEnergia() + energiaConsumida);
                recurso->consumir(energiaConsumida);

                entorno->eliminarElemento(nuevoX, nuevoY);
                entorno->moverElemento(x, y, nuevoX, nuevoY);
                c->setPosicion(nuevoX, nuevoY);
                seMovio = true;
            }
        }
    }

    // Gastar energía aunque no se mueva
    c->setNivelDeEnergia(c->getNivelDeEnergia() - 1);
}