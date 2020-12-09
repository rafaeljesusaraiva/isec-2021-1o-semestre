/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MUNDO.h
 * Author: rafaeljesusaraiva
 *
 * Created on 8 de dezembro de 2020, 21:38
 */

#ifndef MUNDO_H
#define MUNDO_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Territorio.h"
#include "Imperio.h"

using namespace std;


class MUNDO
{
    vector<TERRITORIO> territorios;
    vector<string> tipos = { "planicie", "montanha", "mina", "duna", "castelo", "fortaleza", "refugio_dos_piratas", "pescaria" };
    vector<int> enumeracao = { 0, 0, 0, 0, 0, 0, 0, 0 };
    IMPERIO i;
public:
    //Mundo(){}
    void insere_territorios(string tipo, int num);
    void mostra_territorios() const;
    bool verifica_numero(string num) const;
    void carrega_fich_territorios(string nome_ficheiro);
    void lista_territorios(string terr) const;
    void lista_territorios() const;
    bool verifica_conquista(string nome_t);
    void adiciona_conquista(string terr);
};
int getFatorSorte();
#endif /* MUNDO_H */

