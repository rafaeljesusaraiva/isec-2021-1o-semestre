#include <iostream>
#include <sstream>
#include "msg.h"

using namespace std;

int MSG::proxNumero = 1;

MSG::MSG(char c) : letra(c), numero(proxNumero++) {
    cout << "criado: letra: " << letra << " numero " << numero << endl;
}

MSG::MSG(const MSG &z) {
    letra = z.letra;
    numero = -z.numero;
    cout << "criado por copia: letra: " << letra << " numero " << numero << endl;
}

MSG::~MSG() {
    cout << "destruida: letra: " << letra << " numero " << numero << endl;
}

string MSG::getAsString() const{
    ostringstream os;
    os << "Letra: " << letra << " numero " << numero;
    return os.str();
}