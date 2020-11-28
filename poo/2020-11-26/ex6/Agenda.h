#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Contacto.h"

using namespace std;

class Agenda {
    vector<Contacto *> lista; // os elementos não usados ficarão a NULL
    bool repetido(const string &nome);
public:
    Agenda() {};
    Agenda(const Agenda &a) { *this = a; }
    ~Agenda();

    Agenda &operator = (const Agenda &a);

    bool gravaAgenda(const string &nomeFich);

    bool adicionaContacto(const string nome, unsigned int tel);

    string getAsString() const;

    static Agenda leAgenda(const string &nomeFich);

    // funções para procurar, remover, actualizar, listar. Pode faze-las como TPC
};

ostream &operator << (ostream &os, const Agenda &a);

#endif // !AGENDA_H