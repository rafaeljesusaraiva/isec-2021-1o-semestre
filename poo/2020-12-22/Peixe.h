#ifndef PEIXE_H
#define PEIXE_H

#include <iostream>
#include <sstream>
#include <string>
class Aquario;

using namespace std;

class Peixe {
    static unsigned int conta;
    unsigned int num_serie;
    string especie;
    string cor;
    unsigned int peso = 10;
    Aquario *aquario = nullptr;
    bool indigestao = false;
    unsigned int resta = 4; // eventos de alimentacao ate morrer
protected:
    bool setPeso(int g);
    int getPeso() const { return peso; }
public:
    Peixe(string especie, string cor = "cinzento");
    Peixe(const Peixe &p);

    virtual void come(unsigned int c);

    bool isVivo() const { return (resta > 0); }
    bool ligaAquario(Aquario *a);
    bool desligaAquario(Aquario *a);

    unsigned int getNSerie() const { return num_serie; }
    virtual string getAsString() const;

    Peixe &operator=(const Peixe &p);

    // Destrutor virtual
    virtual ~Peixe();
};
ostream &operator<< (ostream &, const Peixe &);

#endif