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
    void remove_territorio(string nome);
    void mostra_territorios() const;
    bool verifica_numero(string num) const;
    void carrega_fich_territorios(string nome_ficheiro);
    void lista_territorios(string terr) const;
    void lista_territorios() const;
    void lista_imperio() const;
    bool verifica_conquista(string nome_t);
    void adiciona_conquista(string terr);
    
    void executar_evento(string nome, int fase);
    bool aumenta_militar();
    bool aumenta_produtos();
    bool aumenta_ouro();
    bool adiciona_tecnologia(string nome);
    
    bool imperioPerdido() const;
    int tamanhoImperio() const;
    int pontosConquistaImperio() const;
    int obtem_tecnologiaImperio() const;
    
    void produzMateriais();
    
    // DEBUG
    void adiciona_maxForcaMilitar();
};

#endif /* MUNDO_H */

