#include <sstream>
#include "Cliente.h"

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