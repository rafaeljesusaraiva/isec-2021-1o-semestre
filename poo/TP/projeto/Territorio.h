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

    vector<string> default_continente = {"castelo", "duna", "fortaleza", "mina", "montanha", "planicie"};
    vector<string> default_continente_nome = {"Castelo", "Duna", "Fortaleza", "Mina", "Montanha", "Planicie"};
    vector<int> default_continente_resistencia = {7, 4, 8, 5, 6, 5};
    vector<int> default_continente_produto = {3, 1, 0, 0, 0, 1};
    vector<int> default_continente_ouro = {1, 0, 0, 1, 0, 1};
    
    vector<string> default_ilha = {"pescaria", "refugioDosPiratas"};
    vector<string> default_ilha_nome = {"Pescaria", "Refugio dos Piratas"};
    vector<int> default_ilha_resistencia = {9, 9};
    vector<int> default_ilha_produto = {2, 0};
    vector<int> default_ilha_ouro = {0, 1};
    
    bool verifica_territorio(string nome);

public:

    string nome;
    Territorio(const string& n, string& tipo);
    string getAsString() const;
    string get_nome() const;
    int get_resistencia() const;
    int get_criaOuro() const;
    int get_criaProduto() const;
};

#endif /* TERRITORIO_H */

