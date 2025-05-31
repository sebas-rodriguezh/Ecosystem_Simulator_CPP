#pragma once
#include "Criatura.h"
class NodoCriatura
{
private:
	Criatura* c;
	NodoCriatura* sig;

public:
	NodoCriatura(Criatura*, NodoCriatura*);
	~NodoCriatura();
	void setCriatura(Criatura*);
	void setSig(NodoCriatura*);
	NodoCriatura* getSig();
	Criatura* getCriatura();
	
};

