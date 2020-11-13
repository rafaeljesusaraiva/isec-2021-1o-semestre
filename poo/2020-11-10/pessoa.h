#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    string nome;
    string nCC;
    int NIF;
public:
    Pessoa(string no, string bi, int nc):nome(no), nCC(bi), NIF(nc) {};
    string getAsString() const;
    string getCC() const { return nCC; }
    bool setNome(string nn);
};

#endif // !PESSOA_H