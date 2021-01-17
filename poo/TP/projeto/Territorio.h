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
#include <cctype>

using namespace std;

class Territorio
{
    int resistencia;
    int cria_produto;
    int cria_ouro;
    string tipo;

    string default_continente[6] = {"Castelo", "Duna", "Fortaleza", "Mina", "Montanha", "Planicie"};
    string default_ilha[2] = {"Pescaria", "Refugio dos Piratas"};
    
    bool verifica_territorio(string nome);

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

