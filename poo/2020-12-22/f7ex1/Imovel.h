#ifndef IMOVEL_H
#define IMOVEL_H

#include <iostream>
#include <string>
using namespace std;

class Imovel {
    static int conta;
    int area, andar, preco;
    string codigo;
public:
    Imovel(int pr, int ar, int an, string tipo) 
        : area(ar), andar(an), codigo(tipo+to_string(conta++)), preco(pr) {}
    virtual ~Imovel() {}

    string getCodigo() const { return codigo; }
    int getPreco() const { return preco; }
    virtual string getAsString() const;
};
ostream &operator<< (ostream &os, const Imovel &i);

#endif