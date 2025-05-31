#pragma once
#include "NodoCriatura.h"
class ListaCriatura
{
private:
	NodoCriatura* primero;
	NodoCriatura* actual;

public:
	ListaCriatura();
	void insertar(Criatura* c);
	void eliminar(Criatura* c);
	~ListaCriatura();

};

