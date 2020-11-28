#include "Fracao.h"
#include <iostream>
#include <string>
using namespace std;

Fracao::Fracao(int num, int den): numerador(num), denominador(den) {
    if (denominador == 0)
        denominador = 1;
    if (denominador < 0) {
        denominador = -denominador;
        if (numerador < 0) numerador = -numerador;
    }
}

Fracao Fracao::operator *(const Fracao &f) {
    // operador membro
    Fracao m(numerador*f.numerador, denominador*f.denominador);
    return m;
}

Fracao &Fracao::operator ++() {
    numerador += denominador;
    return *this;
}

bool Fracao::setDenominador(int d) {
    if (d == 0)
        return false;
    denominador = d;
    if (denominador < 0) {
        denominador = -denominador;
        numerador = -numerador;
    }
    return true;
}

bool operator == (const Fracao &a, const Fracao &b) {
    if (a.getNumerador() == b.getNumerador() && a.getDenominador() == b.getDenominador())
        return true;
    else return false;
}

Fracao operator * (const Fracao &a, const Fracao &b) {
    // operador funcao global
    Fracao m(a.getNumerador()*b.getNumerador(), a.getDenominador()*b.getDenominador());
    return m;
}

ostream &operator << (ostream &os, Fracao f) {
    os << f.getNumerador() << "/" << f.getDenominador();
    return os;
}