#include <iostream>
#include <vector>
#include <string>
using namespace std;

// class Cozinhador {
//     int id;
// public:
//     Cozinhador(int p) : id(p) {}
//     int getId() const { return id; }
//     virtual void aquece (int temperatura, int minutos) = 0;
//     virtual ~Cozinhador () {}
// };

// // Exaustor.h
// class PanelaPressao;
// class Exaustor {
//     PanelaPressao *panela;
// public:
//     void liga (int minutos);
//     void desligarPanela ();
// };

// // PanelaPressao.h
// class Exaustor;
// class PanelaPressao : public Cozinhador {
//     Exaustor *pExaustor;
//     int ligada = false;
//     int temperatura, minutos;
// public:
//     PanelaPressao (int id, Exaustor &nExaustor): Cozinhador(id), pExaustor(nExaustor) {}
//     void aquece override (int temperatura, int minutos);
//     void desligar ();
//     void diminuiTemperatura ();
// };




// pag 3

class Noticia {
    string titulo, descricao, local;
    int ano, mes, dia;
public:
    Noticia (string t, string ac, string loc, int a, int m, int d) {}
    void mostra_noticia_red() {
        cout << titulo << " - " << local << endl;
        cout << "\t" << descricao << endl;
    }
    int getAno() const { return ano; }
    int getMes() const { return mes; }
}

class Livro {
    int ano;
    vector <Noticia> acontecimentos;
    vector <string> politicos;
public:
    Livro (int iano): ano(iano) {}
    void novaNoticia(Noticia inot, string politico) {
        if (inot.getAno() == ano) {
            acontecimentos.push_back(inot);
            politicos.push_back(politico);
        }
    }
    void mostraAcontecimentos() {
        if (acontecimentos.size() == 0) cout << "Nenhum acontecimento..\n";
        else for (int i=0; acontecimentos.size(); i++) {
            acontecimentos[i].mostra_noticia_red();
        }
    }
    void remove_noticiames(int mes) {
        for (int i=0; i<acontecimentos.size(); i++)
            acontecimentos[i]
    }
};
