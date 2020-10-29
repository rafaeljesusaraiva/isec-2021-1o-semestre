#ifndef PONTO_H
#define PONTO_H

#include <iostream>
#include <string>
using namespace std;

class Ponto {
    int x, y;
public:
    Ponto(int xin = 0, int yin = 0);
    ~Ponto();
    int getX() const;
    int getY() const;
    double distancia(const Ponto &p) const;
    string getAsString() const;

    bool setX(int x);
    bool setY(int y);
};

#endif