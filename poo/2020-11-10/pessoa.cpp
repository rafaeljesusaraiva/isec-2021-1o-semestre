#include <iostream>
#include <sstream>
#include "pessoa.h"

using namespace std;

string Pessoa::getAsString() const {
    ostringstream os;
    os << nome << ", cartao cidadao: " << nCC << ", n contribuinte: " << NIF;
    return os.str();
}

// FALTA: verificar se o nome é valido
bool Pessoa::setNome(string nn) {
    nome = nn;
    return true;
}