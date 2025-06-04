#pragma once
#include "Elemento.h"
#include "Criatura.h"
#include <vector>
#include <iomanip>
#include <thread>


class Entorno {
private:
    string clima;
    int filas;
    int columnas;
    Elemento*** matriz; 
    static Entorno* instancia;
    Entorno(int filas, int columnas);
    vector<string> mensajes; 

public:
    ~Entorno();

    static Entorno* getInstancia(int filas = 10, int columnas = 10);

    bool esPosicionValida(int x, int y) const;
    Elemento* getElemento(int x, int y) const;
    void agregarElemento(Elemento* elem);
    void llenarAleatoriamente();
    void eliminarElemento(int x, int y);

    string moverElemento(int xOrig, int yOrig, int xnueva, int ynueva);

    bool hayAguaAlredorDelRecurso(Recurso* recurso);

    //Cambios para msj. 

    void limpiarMensajes(); 
    const vector<string>& obtenerMensajes() const;
    void agregarMensaje(string mensaje); 

    string imprimir() const;
    void limpiar(); 
     
    //Cambios nuevos. 

    bool moverCriaturaV2(Criatura* c, bool generarRecursoAlMorir);
    string obtenerTipoRecursoParaCriatura(Criatura* c);
    void manejarMuerteCriatura(Criatura* c);
    vector<Criatura*> obtenerSTLCriaturas();
    int contarRecursosDisponibles(); 
    string degradarRecursos();
};
