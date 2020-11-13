#ifndef PONTO_H
#define PONTO_H

#include <string>
using namespace std;

class Ponto {
    int x, y;
public:
    Ponto(int xx=0, int yy=0): x(xx), y(yy) {};
    Ponto &operator ++();

    int getX() const { return x; };
    int getY() const { return y; };
    string getAsString() const;
};

Ponto operator+(const Ponto &a, const Ponto &b);
bool operator==(const Ponto &a, const Ponto &b);
bool operator!=(const Ponto &a, const Ponto &b);
ostream &operator << (ostream &os, const Ponto &p);

#endif // !PONTO_H