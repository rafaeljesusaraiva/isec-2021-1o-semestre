#ifndef PARORDENADO_H
#define PARORDENADO_H

#include <iostream>
using namespace std;

class ParOrdenado {
    int a, b;
public:
    ParOrdenado(int aa, int bb) : a(aa), b(bb) {};
    int getA() const { return a; }
    int getB() const { return b; }
};

ostream &operator << (ostream &os, const ParOrdenado &p);

#endif // !PARORDENADO_H