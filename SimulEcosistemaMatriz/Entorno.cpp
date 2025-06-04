#include "Entorno.h"
#include "FabricaElemento.h"
#include <iostream>

Entorno* Entorno::instancia = nullptr;

Entorno::Entorno(int filas, int columnas) : filas(filas), columnas(columnas) {
    // Crear matriz dinámica
    //puro legner progra1
    matriz = new Elemento * *[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new Elemento * [columnas];
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = nullptr;
        }
    }
   
}

Entorno::~Entorno() {
    limpiar();

    // Liberar memoria de matriz dinámica
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

Entorno* Entorno::getInstancia(int filas, int columnas) {
    if (instancia == nullptr) {
        instancia = new Entorno(filas, columnas);
    }
    return instancia;
}

bool Entorno::esPosicionValida(int x, int y) const {
    return x >= 0 && x < filas && y >= 0 && y < columnas;
}

Elemento* Entorno::getElemento(int x, int y) const {
    if (!esPosicionValida(x, y)) return nullptr;
    return matriz[x][y];
}

void Entorno::agregarElemento(Elemento* elem) {
    int x = elem->getX();
    int y = elem->getY();
    if (esPosicionValida(x, y) && matriz[x][y] == nullptr) {
        matriz[x][y] = elem;
    }
}

void Entorno::llenarAleatoriamente() {
    int totalCeldas = filas * columnas;
    int cantidadCriaturas = totalCeldas * 0.10;
    int cantidadRecursos = totalCeldas * 0.10;

    int colocadas = 0;
    while (colocadas < cantidadCriaturas) {
        int x = rand() % filas;
        int y = rand() % columnas;
        if (matriz[x][y] == nullptr) {
            matriz[x][y] = FabricaElemento::crearCriaturaAleatorio(x, y);
            colocadas++;
        }
    }

    colocadas = 0;
    while (colocadas < cantidadRecursos) {
        int x = rand() % filas;
        int y = rand() % columnas;
        if (matriz[x][y] == nullptr) {
            matriz[x][y] = FabricaElemento::crearRecursoAleatorio(x, y);
            colocadas++;
        }
    }
}


void Entorno::eliminarElemento(int x, int y) {
    if (esPosicionValida(x, y) && matriz[x][y] != nullptr) {
        Elemento* e = matriz[x][y];
        if (e != nullptr) {
            delete e;
            matriz[x][y] = nullptr;
        }
    }
}

void Entorno::limpiarMensajes() {
    mensajes.clear(); 
}

const vector<string>& Entorno::obtenerMensajes() const {
    return mensajes;
}
void Entorno::agregarMensaje(string mensaje) {
    mensajes.push_back(mensaje);
}


string Entorno::moverElemento(int xOrig, int yOrig, int xDest, int yDest) 
{
    stringstream s; 

    if (!esPosicionValida(xOrig, yOrig) || !esPosicionValida(xDest, yDest)) {
        s << "[Entorno] Movimiento fuera de rango\n";
        return s.str();
    }
    if (matriz[xOrig][yOrig] == nullptr) {
        s << "[Entorno] No hay elemento en la posición origen (" << xOrig << ", " << yOrig << ")\n";
        return s.str();
    }
    if (matriz[xDest][yDest] != nullptr) {
        s << "[Entorno] Posición destino ocupada (" << xDest << ", " << yDest << ")\n";
        return s.str();
    }
    s << "[Entorno] Moviendo elemento de (" << xOrig << ", " << yOrig << ") a (" << xDest << ", " << yDest << ")\n";
    matriz[xDest][yDest] = matriz[xOrig][yOrig];
    matriz[xOrig][yOrig] = nullptr;
    matriz[xDest][yDest]->setPosicion(xDest, yDest);

    return s.str(); 
}




//void Entorno::imprimir() const {
//    for (int i = 0; i < filas; i++) {
//        for (int j = 0; j < columnas; j++) {
//            if (matriz[i][j] != nullptr) {
//                std::cout << matriz[i][j]->tipo()[0] << " ";
//            }
//            else {
//                cout << ". ";
//            }
//        }
//        cout << "\n";
//    }
//}


string Entorno::imprimir() const {
    stringstream s; 

    s << "   ";
    for (int j = 0; j < columnas; ++j) {
        s << " " << j << " ";  // Columnas numeradas
    }
    s << "\n";

    // Matriz con coordenadas de fila
    for (int i = 0; i < filas; ++i) {
        s << i << " ";  // Número de fila al inicio

        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] != nullptr) {
                s << " " << matriz[i][j]->tipo()[0] << " "; // Solo primera letra
            }
            else {
                s << " . ";  // Punto para celdas vacías
            }
        }
        s << "\n";  // Salto de línea después de cada fila
    }

    return s.str(); 
}


void Entorno::limpiar() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] != nullptr) {
                delete matriz[i][j];
                matriz[i][j] = nullptr;
            }
        }
    }
}

//Metodos nuevos despues del cambio.



string Entorno::degradarRecursos() {
    stringstream s; 

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            Elemento* elem = matriz[i][j];

            if (Recurso* recurso = dynamic_cast<Recurso*>(elem)) {
                recurso->reducirEnergia();

                if (recurso->getNivelDeEnergia() <= 0) {
                    s << "[" << recurso->tipo() << "] Recurso en (" << i << ", " << j << ") murio por agotamiento.\n"; 
                    eliminarElemento(i, j);
                }
            }
        }
    }
    return s.str();
}


int Entorno::contarRecursosDisponibles() 
{
    int count = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (dynamic_cast<Recurso*>(matriz[i][j])) {
                ++count;
            }
        }
    }
    return count;
}



vector<Criatura*> Entorno::obtenerSTLCriaturas() {
    vector<Criatura*> criaturas;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (Criatura* c = dynamic_cast<Criatura*>(matriz[i][j])) {
                criaturas.push_back(c);
            }
        }
    }
    return criaturas;
}

string Entorno::obtenerTipoRecursoParaCriatura(Criatura* c) {
    if (dynamic_cast<Carnivoro*>(c)) {
        return "Carne";
    }
    else if (dynamic_cast<Herbivoro*>(c)) {
        return "Planta";
    }
    else if (dynamic_cast<Omnivoro*>(c)) {
        return (rand() % 2 == 0) ? "Carne" : "Planta"; // 50% de probabilidad
    }
    return "Planta"; // Default
}

void Entorno::manejarMuerteCriatura(Criatura* c) {
    string tipoRecurso = obtenerTipoRecursoParaCriatura(c);
    int x = c->getX();
    int y = c->getY();

    // 1. Primero eliminar la criatura
    eliminarElemento(x, y);  // Esto libera la posición

    // 2. Luego agregar el recurso en la posición ahora vacía
    if (Elemento* nuevoRecurso = FabricaElemento::crearRecursoDeTipo(tipoRecurso, x, y)) {
        agregarElemento(nuevoRecurso);
    }
}


bool Entorno::moverCriaturaV2(Criatura* c, bool generarRecursoAlMorir) {
    if (c == nullptr || c->getNivelDeEnergia() <= 0) {
        if (c != nullptr && generarRecursoAlMorir) {
            agregarMensaje("["+c->tipo()+"] en ("+to_string(c->getX())+", "+ to_string(c->getY())+") murio por falta de energia y genero recurso.");
            manejarMuerteCriatura(c); // Genera recurso y elimina
        }
        return false;
    }

    int xViejo = c->getX();
    int yViejo = c->getY();
    pair<int, int> nuevaPos = c->mover();

    if (esPosicionValida(nuevaPos.first, nuevaPos.second)) {
        Elemento* destino = getElemento(nuevaPos.first, nuevaPos.second);

        if (matriz[nuevaPos.first][nuevaPos.second] == nullptr) {
            c->setX(nuevaPos.first);
            c->setY(nuevaPos.second);

            this->agregarMensaje(this->moverElemento(xViejo, yViejo, c->getX(), c->getY()));
       
        }
        else {
            if (nuevaPos.first == c->getX() && nuevaPos.second == c->getY()) {
                
                this->agregarMensaje("[" + c->tipo() + "] en (" + to_string(c->getX()) + ", " + to_string(c->getY()) + "): Se quedo quieto.");
                   
            }
            else {
                if (Recurso* recursoPosible = dynamic_cast<Recurso*>(destino)) {
                    if (c->puedeConsumir(recursoPosible)) {
                        this->agregarMensaje(c->alimentar(recursoPosible));
                        int xR = recursoPosible->getX();
                        int yR = recursoPosible->getY();
                        eliminarElemento(xR, yR);
                        this->agregarMensaje(moverElemento(c->getX(), c->getY(), xR, yR));
                    }
                    else {
                        agregarMensaje("[" + c->tipo() + "] en (" + to_string(c->getX()) + ", " + to_string(c->getY()) + "): No pudo comer " + recursoPosible->tipo() + " en (" + to_string(recursoPosible->getX()) + ", " + to_string(recursoPosible->getY()) + "), porque NO es de su tipo de alimentacion.");
                    }
                }
                else if (Criatura* pareja = dynamic_cast<Criatura*>(destino)) {
                    agregarMensaje("[" + c->tipo() + "] en (" + to_string(c->getX()) + ", " + to_string(c->getY()) + "): Encontro pareja [" + pareja->tipo() + "] en (" + to_string(pareja->getX()) + ", " + to_string(pareja->getY()) + ")");


                    if (c->puedeReproducirseCon(pareja)) {
                        Criatura* hijo = c->reproducir(c, pareja);
                        hijo->setNivelDeEnergia((c->getNivelDeEnergia() + pareja->getNivelDeEnergia()) / 4);
                        hijo->setEdad(1);

                        for (int i = -1; i <= 1; i++) {
                            for (int j = -1; j <= 1; j++) {
                                int x = c->getX() + i;
                                int y = c->getY() + j;
                                if (esPosicionValida(x, y) && getElemento(x, y) == nullptr) {
                                    hijo->setPos(x, y);
                                    agregarElemento(hijo);
                                    return true;
                                }

                                x = pareja->getX() + i;
                                y = pareja->getY() + j;
                                if (esPosicionValida(x, y) && getElemento(x, y) == nullptr) {
                                    hijo->setPos(x, y);
                                    agregarElemento(hijo);
                                    return true;
                                }
                            }
                        }

                        for (int intentos = 0; intentos < 10; intentos++) {
                            int x = rand() % filas;
                            int y = rand() % columnas;
                            if (getElemento(x, y) == nullptr) {
                                hijo->setPos(x, y);
                                agregarElemento(hijo);
                                return true;
                            }
                        }

                        delete hijo;
                    }
                    else {
                        if (c->tipo() == pareja->tipo()) 
                        {
                            agregarMensaje("No se pueden reproducir por niveles de energia de los padres:");
                            agregarMensaje("Padre 1: " + to_string(c->getNivelDeEnergia()));
                            agregarMensaje("Padre 2: " + to_string(pareja->getNivelDeEnergia()));
                        }
                        else {
                            agregarMensaje("No pudo reproducirse por NO ser de la misma especie.");
                        }


                       
                    }
                }
            }
        }
    }

    c->setEdad(c->getEdad() + 1);
    c->setNivelDeEnergia(c->getNivelDeEnergia() - 10);

    if (c->getNivelDeEnergia() <= 0 && generarRecursoAlMorir) {
        agregarMensaje("[" + c->tipo() + "] en (" + to_string(c->getX()) + ", " + to_string(c->getY()) + ") murio por falta de energia y genero recurso.");
        manejarMuerteCriatura(c);
        return false;
    }

    return c->getNivelDeEnergia() > 0; 

}
