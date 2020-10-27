#ifndef TELEVISAO_H
#define TELEVISAO_H
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using namespace std;

class Televisao {
    static const int MAX_CANAIS = 10; // a) max 10 canais
    vector<string> canais;
    bool ligada = false;
    unsigned som = 0; // inteiro não negativo
    unsigned canalAtual; // 1 para o 1º canal, ...
public:
    Televisao(initializer_list<string> ca);
    string getAsString() const;
    bool liga(); // uma TV sem canais não liga
    void desliga();
};

#endif // !TELEVISAO_H