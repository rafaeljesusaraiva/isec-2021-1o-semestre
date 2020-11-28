#ifndef CLUBE_H
#define CLUBE_H
#include "Pessoa.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Clube {
    Pessoa **socios;
    unsigned int tam;
    unsigned int nSocios = 0;
public:
    Clube (unsigned int t);
    Clube (const Clube &r);
    ~Clube ();

    Clube &operator=(const Clube &r);
    string getAsString() const;
    bool setMembroDoClube(Pessoa * p);
};

#endif // !CLUBE_H