#ifndef CADERNO_H
#define CADERNO_H

#include <iostream>
#include <string>
using namespace std;

class Caderno {
    string marca, cor, local, conteudo;
    int nPag, pagAtual;
    double altura, largura;
    bool aberto = false;

public:
    // construtor
    Caderno(string inMar, string inCor, int inNPag, double inAlt, double inLarg) : marca(inMar), cor(inCor), altura(inAlt), largura(inLarg) {
        if (inNPag >= 1)
            nPag = inNPag;
        else nPag = 0;
        conteudo = "Pg 1: ";
        pagAtual = 1;
    }
    // Destrutor
    ~Caderno() {
        cout << "Tenho conteudo : \n" << conteudo << "\nE vou desaparacer!" << endl;
    }
    // Acessores
    string getMarca() const { return marca; };
    string getCor() const { return cor; }
    string getLocal() const { return local; };
    string getConteudo() const { return conteudo; };
    double getAltura() const { return altura; };
    double getLargura() const { return largura; };
    int getNPag() const { return nPag; };
    // Modificadores
    void abrir();
    void fechar();
    bool setLocal(string loc);
    bool escreve(string texto);
    bool viraPagina();
};

#endif // !CADERNO_H