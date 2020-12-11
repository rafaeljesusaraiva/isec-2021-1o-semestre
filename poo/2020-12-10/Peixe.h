#ifndef PEIXE_H
#define PEIXE_H

#include <sstream>
#include <string>

using namespace std;

class Aquario;
class Peixe {
    static unsigned int conta;
    unsigned int num_serie;
    string especie;
    string cor;
    unsigned int peso = 10;
    Aquario *aquario = nullptr;
    bool indigestao = false;
    unsigned int resta = 4;
public:
    Peixe(string especie, string cor = "cinzento");
    string getAsString() const;
};

ostream &operator << (ostream &, const Peixe &);

#endif