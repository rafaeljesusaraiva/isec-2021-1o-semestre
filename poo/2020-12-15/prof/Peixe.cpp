#include <iostream>
#include <sstream>
#include "Peixe.h"
#include "Aquario.h"

unsigned int Peixe::conta = 500;
double getRealUniform();

void Peixe::come(unsigned int c) {
	if (indigestao){ 
		if( resta > 0) 
			--resta;
		return;
	}
	peso += c;
	if (peso > 50) {
		if (getRealUniform() > 0.5) {
			indigestao = true;
			peso /= 2;
		}
		else {
			peso = 40;
			Peixe *peixinho = new Peixe(especie + "D", cor);
			aquario->addPeixe(peixinho);
		}
	}
}


bool Peixe::ligaAquario(Aquario *a) {
	if (a == nullptr || aquario != nullptr)
		return false;
	aquario = a;
	return true;
}

string Peixe::getAsString() const {
	ostringstream os;
	os << "numero de serie: " << nSerie << ", cor: " << cor;
	os << ", especie: " << especie << ", peso: " << peso;
	return os.str();
}

ostream &operator<<(ostream &os, const Peixe &p) {
	os << p.getAsString();
	return os;
}

