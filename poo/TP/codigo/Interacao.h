#ifndef INTERACAO_H
#define INTERACAO_H

#include <iostream>
#include <fstream>
#include <string>
#include "Mundo.h"

using namespace std;

class Mundo;

class Interacao {
    Mundo mundo;
    string comando;
    bool fim;

    void processComando();
    // carregar mundo p/ ficheiro > carrega
    bool setMundo(string fichName);
    // carregar mundo normal > cria
    bool setMundo();
public:
    Interacao() { fim = false; }
    ~Interacao() { delete mundo; }
    void setComando();
    bool getFim() { return fim; }
};

#endif // INTERACAO_H