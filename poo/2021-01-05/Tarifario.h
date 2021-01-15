#ifndef TARIFARIO_H
#define TARIFARIO_H

#include <vector>
#include <string>
using namespace std;

class Tarifario {
    vector<int> duracoes;
protected:
    void apagaTreinos();
public:
    virtual ~Tarifario() = default;
    
    int getNumTreinos() const { return duracoes.size(); }
    int getDuracaoTreinoI(size_t i);
    bool acrescentaTreinos(int dur);
    virtual int calculaPagamento() = 0; // comentado para testes
    /*{   // corpo usado para testar funcoes da classe
        apagaTreinos();
        return 0;
    } */
    virtual string getAsString() const;
};
ostream &operator<< (ostream &os, const Tarifario &t);

#endif