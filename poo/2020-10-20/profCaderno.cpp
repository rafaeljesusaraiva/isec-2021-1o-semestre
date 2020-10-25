#include <iostream>
#include <string>
#include "caderno.h"

string Caderno::getMarca() const {    return marca;}
string Caderno::getCor() const {    return cor;}
string Caderno::getLocal() const {    return local;}
string Caderno::getConteudo() const { return conteudo; }
double Caderno::getAltura() const { return altura; }
double Caderno::getLargura() const { return largura; }
int Caderno::getNumeroPag() const { return nPag; }
/*Caderno::Caderno(string marca, string cor, int nPag, double altura, 
    double largura) {
    this->marca = marca;
    this->cor = cor;
    this->altura = altura;
    this->largura = largura;
    if (nPag > 1)
        this->nPag = nPag;
    else
        this->nPag = 1;
    conteudo = "Pag. 1: ";
}
*/
Caderno::Caderno(string m, string c, int nP, double a, double l) :
    marca{ m }, cor{ c }, altura(a), largura(l) {
    if (nP >= 1)
        nPag = nP;
    else
        nPag = 1;
    conteudo = "Pag 1: ";
    pagAtual = 1;
}
void Caderno::abrir() { aberto = true; }
void Caderno::fechar() { aberto = false; }
bool Caderno::setLocal(string loc) {
    if (!aberto) {
        local = loc;
        return true;
    }
    return false;
}
/*Caderno::~Caderno() {
    cout << "tenho conteudo: " << conteudo << " e vou desaparecer!\n" << endl;
}*/
bool Caderno::escreve(string texto) {
    if (aberto && local != "") {
        conteudo += texto;
        return true;
    }
    return false;
}
bool Caderno::viraPagina() {
    if (aberto && pagAtual < nPag) {
        ++pagAtual;
        conteudo += "\nPag. " + to_string(pagAtual) + ": ";
        return true;
    }
    return false;
}
int main()
{
    Caderno c("Oxford", "verde", 80, 50, 30);
    c.setLocal("prateleira 2A");
    c.abrir();
    c.escreve("Estava um dia escuro de tempestade.\n");
    c.viraPagina();
    c.escreve("E no outro dia choveu outra vez.\n");
    cout << c.getConteudo() << endl;

    /*   cout << "Marca do caderno: " << c.getMarca() << "\n";
//   cout << "numero de paginas: " << c.getNumeroPag() << "\n";
//    if (c.setLocal("prateleira 2A"))
        cout << "Arrumei o caderno.\n";
    else
        cout << "Nao consegui mudar\n";
*/
}
