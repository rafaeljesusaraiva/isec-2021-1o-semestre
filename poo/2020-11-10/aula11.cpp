#include <iostream>
#include <fstream>
#include <string>
#include "pessoa.h"
#include "conta.h"
#include "Banco.h"
using namespace std;

bool getDadosPessoa(istream &is, string &s, string &bi, int &nif) {
    getline(is, s);
    is >> s >> nif;
    if (is.fail() == true) {
        is.clear();
        s = "";
        bi = "";
        nif = -1;
        return false;
    }
    return true;
}

int main() {

    Banco b("Banco XPTO");
    // cout << "Banco b: " << b.getAsString() << endl;

    string nomeP, ccP;
    int numCont;
    ifstream f("dados.txt");
    getDadosPessoa(f, nomeP, ccP, numCont);
    f.close();
    Pessoa pIn(nomeP, ccP, numCont);
    cout << pIn.getAsString() << endl;


    cout << "\n\n";
    Pessoa p("Maria Joao Silva", "1231231232ER1", 123123123);
    // cout << "Pessoa: " << endl;
    // cout << p.getAsString() << "\n";
    Conta c(&p);
    cout << "Conta: " << c.getAsString() << "\n";
    // c.deposita(100);
    // cout << c.getAsString() << "\n";
    // c.levanta(100);
    // cout << c.getAsString() << "\n";
    c.getTitular()->getAsString();

    Pessoa p2("Joao Santos", "3213213212ER1", 321321321);
    Conta c2(&p2);
    cout << "Conta 2: " << c2.getAsString() << "\n";

    b.addConta(c);
    b.addConta(c2);
    cout << "Banco b: " << b.getAsString() << endl;

    b.deposita(p2.getCC(), 100);
    cout << "Depois deposito:" << endl;
    cout << "Banco b: " << b.getAsString() << endl;

    b.delConta(p2.getCC());
    cout << "Banco b: " << b.getAsString() << endl;
    return 0;
}