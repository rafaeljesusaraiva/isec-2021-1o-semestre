#include <iostream>

#include "Caderno.h"

using namespace std;

void Caderno::abrir() { aberto = true; }
void Caderno::fechar() { aberto = false; }
bool Caderno::setLocal(string loc) {
    if (!aberto) {
        local = loc;
        return true;
    }
    return false;
}
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
        conteudo += "\nPg " + to_string(pagAtual) + ": ";
        return true;
    }
    return false;
}

int main() {
    Caderno c("Textos Editora", "Preto", 36, 10, 15);

    cout << "Marca do Caderno: " << c.getMarca() << endl;
    cout << "Numero Paginas: " << c.getNPag() << endl;
    c.setLocal("Prateleira 2A");
    c.abrir();
    c.escreve("Estava um dia escuro de tempestade...");
    c.viraPagina();
    c.escreve("E choveu chuva...");
    cout << c.getConteudo() << endl;
}