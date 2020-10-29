#ifndef RETANGULO_H
#define RETANGULO_H

#include "ponto.h"
#include <iostream>

using namespace std;

class Retangulo {
    Ponto cse;
    double altura, largura;
public:
    Retangulo(const Ponto &p, double alt, double lar);
    ~Retangulo();
    
    string getAsString() const;
    double area() const;

    void setCanto(const Ponto &p);
};

#endif