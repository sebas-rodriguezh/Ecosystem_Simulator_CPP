#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Elemento
{
protected:
	int x;
	int y;
	//Coordenadas del Elemento, ya que siempre estara en la matriz. 
public:
	Elemento(int xAux = 0, int yAux = 0);
	virtual ~Elemento();

	void setX(int xAux);
	void setY(int yAux);

	int getX();
	int getY();

	void setPosicion(int nuevaX, int nuevoY);

	virtual string tipo() = 0;
	//virtual string toString() = 0; 
};