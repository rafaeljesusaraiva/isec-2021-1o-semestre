#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Contacto { // Isto é para fazer copy & paste
    string nome; // para o programa no computador.
    unsigned int tel; // Mas pode nem ser sequer preciso
public: // -> Ver primeiro as perguntas.
    Contacto(string n, unsigned int t) : nome(n), tel(t) {}
    string getNome() const { return nome; }
    int getTel() const { return tel; }
    void setNome(string s) { nome = s; }
    void setTel(unsigned int t) { tel = t; }
}; 

#endif // !CONTACTO_H