#include <sstream>
#include "Cliente.h"

Cliente::Cliente(const Cliente &c) {
    *this = c;
}

Cliente &Cliente::operator= (const Cliente &c) {
    if (this == &c)
        return *this;
    if (tarifario) {
        delete tarifario;
        tarifario = nullptr;
    }  
    nome = c.nome;
    cc = c.cc;
    inicio = c.inicio;
    aTreinar = c.aTreinar;
    if (c.tarifario)
        tarifario = c.tarifario->clone();
    return *this;
}

string Cliente::getAsString() const {
    ostringstream os;
    os << nome << " cc: " << cc << " ";
    if (tarifario)
        os << *tarifario;
    return os.str();
}

bool Cliente::iniciaTreino(int i) {
    if (aTreinar)
        return false;
    inicio = i;
    aTreinar = true;
    return true;
}

bool Cliente::terminaTreino(int f) {
    if (!aTreinar || !tarifario)
        return false;
    aTreinar = false;
    tarifario->acrescentaTreinos(f - inicio);
    return true;
}

int Cliente::paga() {
    if (!tarifario)
        return -1;
    return tarifario->calculaPagamento();
}

ostream &operator<< (ostream &os, const Cliente &c) {
    os << c.getAsString();
    return os;
}