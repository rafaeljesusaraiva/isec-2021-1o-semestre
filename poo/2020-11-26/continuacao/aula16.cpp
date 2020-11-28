#include <iostream>
#include <vector>
#include "Clube.h"

int main() {

    vector<Pessoa> populacao;
    populacao.push_back(Pessoa("Joao", 10));
    populacao.push_back(Pessoa("Maria", 20));
    populacao.push_back(Pessoa("Jose", 30));
    Clube c(50);

    c.setMembroDoClube(&populacao[0]);
    c.setMembroDoClube(&populacao[1]);
    c.setMembroDoClube(&populacao[2]);

    populacao.push_back(Pessoa("Rita", 40));
    // c.setMembroDoClube(&populacao[3]);

    cout << "Clube c: " << c.getAsString() << endl;

    // pesca.setMembroDoClube(&p1);
    // pesca.setMembroDoClube(&p2);

    // cout << "Filatelia: " << filatelia.getAsString() << endl;
    // cout << "Pesca: " << pesca.getAsString() << endl;

    // Clube c3 = pesca;
    // cout << "C3: " << c3.getAsString() << endl;

    // Clube c4(filatelia);
    // cout << "C4: " << c4.getAsString() << endl;
}