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

int getFatorSorte();

class Mundo {
    vector<Territorio> territorios;
    vector<string> tipos = { "planicie", "montanha", "mina", "duna", "castelo", "fortaleza", "refugio_dos_piratas", "pescaria" };
    vector<int> enumeracao = { 0, 0, 0, 0, 0, 0, 0, 0 };
    Imperio imperio;
public:
    //Mundo();
    void insere_territorios(string tipo, int num);
    void mostra_territorios() const;
    bool verifica_numero(string num) const;
    void carrega_fich_territorios(string nome_ficheiro);
    void lista_territorios(string terr) const;
    void lista_territorios() const;
    bool verifica_conquista(string nome_t);
    void adiciona_conquista(string terr);
    
    void executar_evento(string nome, int fase) {
        imperio.evento_aleatorio(nome, fase);
    }
    void aumenta_militar();
    void aumenta_tecnologia();
    void aumenta_produtos();
    void aumenta_ouro();
    
    // DEBUG
    void adiciona_maxForcaMilitar() {
        imperio.set_capacidadeForcaMilitar(20);
        imperio.set_forcaMilitar(imperio.get_capacidadeForcaMilitar());
        cout << "[DEV] Forca militar maximizada (" << imperio.get_forcaMilitar() << "/" << imperio.get_capacidadeForcaMilitar() << ") !" << endl;
    }
};

#endif /* MUNDO_H */

