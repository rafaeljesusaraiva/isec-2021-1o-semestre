#ifndef FRACAO_H
#define FRACAO_H
#include <iostream>
using namespace std;

class Fracao {
    int numerador, denominador;
public: 
    Fracao(int num=0, int den=1);
    operator int() const { return (numerador/denominador); }

    Fracao operator *(const Fracao &f);
    Fracao &operator ++();

    int getNumerador() const { return numerador; }
    int getDenominador() const { return denominador; }
    void setNumerador(int n) { numerador = n; }
    bool setDenominador(int d);
};

bool operator == (const Fracao &a, const Fracao &b);
Fracao operator * (const Fracao &a, const Fracao &b);
ostream &operator << (ostream &os, Fracao f);

#endif // !FRACAO_H