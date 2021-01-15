#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Tarifario.h"

class Cliente {
    string nome;
    int cc;
    Tarifario *tarifario = nullptr;
    int inicio;
    bool aTreinar = false;
public: 
    Cliente(string no, int ncc, Tarifario *t)
        : nome(no), cc(ncc), tarifario(t), inicio(0) {}
    Cliente(const Cliente &);
    Cliente &operator= (const Cliente &c);
    virtual ~Cliente() { delete tarifario; }

    virtual string getAsString() const;
    virtual bool iniciaTreino(int i);
    virtual bool terminaTreino(int f);
    virtual int paga();

    // virtual void reageEntrada() = 0;
    // virtual void reageSaida() = 0; 
};
ostream &operator<< (ostream &os, const Cliente &c);

#endif