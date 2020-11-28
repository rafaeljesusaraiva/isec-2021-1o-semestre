#ifndef PONTO_H
#define PONTO_H

#include "ParOrdenado.h"
#include <string>
using namespace std;

class Ponto {
    int x, y;
public:
    explicit Ponto(int xx=0, int yy=0): x(xx), y(yy) {};
    
    operator ParOrdenado() const { return ParOrdenado(x, y); }

    // Caso não se declare com "friend", teria de usar funções setY() e setX() para conseguir alterar
    friend istream &operator >> (istream &os, Ponto &p);

    // Incremento pré-fixo
    Ponto &operator ++();
    Ponto &operator +=(const Ponto &p);
    // Incremento pós-fixo (não muito usado)
    Ponto operator ++(int);

    int getX() const { return x; };
    int getY() const { return y; };
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    string getAsString() const;
};

Ponto operator+(const Ponto &a, const Ponto &b);
bool operator==(const Ponto &a, const Ponto &b);
bool operator!=(const Ponto &a, const Ponto &b);
ostream &operator << (ostream &os, const Ponto &p);

#endif // !PONTO_H