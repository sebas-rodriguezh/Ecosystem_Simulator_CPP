#pragma once
#include "Elemento.h"
#include "ListaCriatura.h"
class Entorno {
private:
    int filas;
    int columnas;
    Elemento*** matriz; // Matriz dinámica de punteros a Elemento
    ListaCriatura* listaC;
    static Entorno* instancia;//singleton
    Entorno(int filas, int columnas);

public:
    ~Entorno();

    static Entorno* getInstancia(int filas = 10, int columnas = 10);

    bool esPosicionValida(int x, int y) const;
    Elemento* getElemento(int x, int y) const;
    void agregarElemento(Elemento* elem);
    void llenarAleatoriamente();
    void eliminarElemento(int x, int y);

    void moverElemento(int xOrig, int yOrig, int xnueva, int ynueva);
    // void moverTodasLasCriaturasAleatoriamente();

    void imprimir() const;
    void limpiar(); 
     

};
