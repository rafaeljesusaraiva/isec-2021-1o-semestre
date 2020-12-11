#include "Peixe.h"

unsigned int Peixe::conta = 500;

Peixe::Peixe(string especie, string cor):especie(especie), cor(cor), num_serie(conta++) {}

string Peixe::getAsString() const {
    ostringstream os;
    os << "N. Serie: " << num_serie << " || Especie: " << especie;
    os << " || Cor: " << cor << " || Peso: " << peso;
    return os.str();
}

ostream &operator << (ostream &os, const Peixe &p) {
    os << p.getAsString();
    return os;
}