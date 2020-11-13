#include <iostream>
#include <sstream>
#include "conta.h"

using namespace std;

bool Conta::levanta(int quantia) {
    if (quantia < 0 || quantia > saldo)
        return false;
    else 
        saldo -= quantia;
    return true;
}

bool Conta::deposita(int quantia) {
    if (quantia < 0)
        return false;
    else
        saldo += quantia;
    return true;
}

string Conta::getAsString() const {
    ostringstream os;
    os << titular->getAsString() << ", saldo: " << saldo;
    return os.str(); 
}