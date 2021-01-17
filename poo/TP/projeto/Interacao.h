/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   INTERACAO.h
 * Author: rafaeljesusaraiva
 *
 * Created on 28 de dezembro de 2020, 19:25
 */

#ifndef INTERACAO_H
#define INTERACAO_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <time.h>

#include "Mundo.h"
#include "Imperio.h"
#include "Territorio.h"
//#include "Tecnologia.h"

using namespace std;

class Interacao {
    Mundo mundo;
public:
    Interacao();
    int configuracao_cria(vector<string> com_args);
    void configuracao_lista(vector<string> com_args);
    void mostra_ajuda_configuracao();
    void menu();
    void mostra_ajuda_jogo();
    vector<string> separa_args(string comando, vector<string>& args);
};

#endif /* INTERACAO_H */

