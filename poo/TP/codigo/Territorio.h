/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TERRITORIO.h
 * Author: rafaeljesusaraiva
 *
 * Created on 8 de dezembro de 2020, 21:39
 */

#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class TERRITORIO
{
    int resistencia;
    int cria_produto;
    int cria_ouro;

    /*
     *  Continente
     *      > Castelo, Duna, Fortaleza, Mina, Montanha, Planicie
     * 
     *  Ilhas
     *      > Pescaria, Refugio dos Piratas
     */

public:

    string nome;
    TERRITORIO(const string& n, const int& in_resistencia, int& in_criaProduto, int& in_criaOuro);
    string getAsString() const;
    string get_nome() const;
    int get_resistencia() const;
};

#endif /* TERRITORIO_H */

