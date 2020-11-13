#ifndef DESENHO_H
#define DESENHO_H

#include "ponto.h"
#include "retangulo.h"
#include <iostream>
#include <vector>

using namespace std;

class Desenho {
    string nome;
    vector<Retangulo> figuras;
public:
    Desenho(string n) : nome(n) {};

    string getAsString() const;

    bool addFigura(Retangulo &r);
    void removeAreaMaior(double a);
};

#endif