#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    string nome;
    int idade;
public:
    Pessoa (string n, int i):nome(n), idade(i) {
        if (idade < 0) idade = 0;
    }
    string getNome() const { return nome; }
    int getIdade() const { return idade; }
};
ostream &operator << (ostream &os, const Pessoa &p);

#endif // !PESSOA_H