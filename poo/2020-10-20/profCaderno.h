#ifndef CADERNO_H
#define CADERNO_H

using namespace std;
class Caderno {
    string marca;
    string cor;
    double altura;
    double largura;
    int nPag;
    string local;
    string conteudo;
    bool aberto = false;
    int pagAtual;
public:
    //construtor
    Caderno(string marca, string cor, int nPag, double altura, double largura);
    //destrutor
     //~Caderno();
     //acessores
    string getMarca() const;
    string getCor() const;
    string getLocal() const;
    string getConteudo() const;
    double getAltura() const;
    double getLargura() const;
    int getNumeroPag() const;
    //modificadores
    void abrir();
    void fechar();
    bool setLocal(string loc);
    bool escreve(string texto);
    bool viraPagina();
};
#endif //CADERNO_H

