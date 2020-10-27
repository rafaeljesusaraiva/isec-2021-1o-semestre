#include <iostream>
#include <sstream>
#include <string>
#include <sstream>
#include <initializer_list>
#include "televisao.h"

using namespace std;

// Inicializador a)
/*Televisao::Televisao(initializer_list<string> ca) {
    int n = 0;
    for (auto c : ca)
        if (n < MAX_CANAIS) {
            canais.push_back(c);
            n++;
        }
    if (!canais.empty())
        canalAtual = 1;
}*/

// Inicializador b)
Televisao::Televisao(initializer_list<string> ca) : canais(ca) {
    if (!canais.empty())
        canalAtual = 1;
}

string Televisao::getAsString() const {
    ostringstream os;
    if (ligada)
        os << "TV ligada, ";
    else
        os << "TV desligada, ";
    if (!canais.empty())
        os << "no canal " << canalAtual << ": " << canais[canalAtual-1] << ", ";
    os << "com som no nivel " << som << ", ";
    if (!canais.empty())
        os << "com os canais: ";
        for (auto c : canais)
            os << c << " ";
    return os.str();
}

bool Televisao::liga() {
    if (!canais.empty()) {
        ligada = true;
        return true;
    } else return false;
}

void Televisao::desliga() { ligada = false; }