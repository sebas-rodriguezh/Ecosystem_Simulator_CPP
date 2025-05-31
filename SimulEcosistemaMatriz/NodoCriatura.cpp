#include "NodoCriatura.h"

NodoCriatura::NodoCriatura(Criatura* c_, NodoCriatura* sig_) {
	c = c_;
	sig = sig_;
}

NodoCriatura::~NodoCriatura() {
	delete c;
}

void NodoCriatura::setCriatura(Criatura* c_) {
	c = c_;
}
void NodoCriatura::setSig(NodoCriatura* sig_) {
	sig = sig_;
}
NodoCriatura* NodoCriatura::getSig() {
	return sig;
}
Criatura* NodoCriatura::getCriatura() {
	return c;
}
