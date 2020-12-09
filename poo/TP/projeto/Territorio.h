/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Territorio.h
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

class Territorio
{
    int resistencia;
    int cria_produto;
    int cria_ouro;

    /*
     *  Ainda não há verificacao de nomes
     * 
     *  Continente
     *      > Castelo, Duna, Fortaleza, Mina, Montanha, Planicie
     * 
     *  Ilhas
     *      > Pescaria, Refugio dos Piratas
     */

public:

    string nome;
    Territorio(const string& n, const int& in_resistencia, int& in_criaProduto, int& in_criaOuro);
    string getAsString() const;
    string get_nome() const;
    int get_resistencia() const;
    int get_criaOuro() const;
    int get_criaProduto() const;
};

#endif /* TERRITORIO_H */

