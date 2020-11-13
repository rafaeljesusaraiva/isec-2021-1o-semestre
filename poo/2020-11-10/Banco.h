#ifndef BANCO_H
#define BANCO_H
#include "conta.h"
#include <vector>

using namespace std;

class Banco {
    string nome;
    vector<Conta> contas;
public:
    Banco(string no):nome(no){};
    string getAsString() const;

    bool addConta(Conta c);
    bool delConta(const string &bi);
    bool deposita(const string &bi, int quantia);
};

#endif // !BANCO_H