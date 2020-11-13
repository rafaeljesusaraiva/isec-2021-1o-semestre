#ifndef CONTA_H
#define CONTA_H
#include "pessoa.h"

class Conta {
    Pessoa *titular; // repres. p Referência
    int saldo = 0;
public:
    Conta(Pessoa *pessoa):titular(pessoa) {};
    bool levanta(int quantia);
    bool deposita(int quantia);
    const Pessoa *getTitular() const {
        return titular;
    }
    string getAsString() const;
};

#endif // !CONTA_H