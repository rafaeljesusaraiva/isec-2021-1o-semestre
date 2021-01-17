/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Imperio.h
 * Author: rafaeljesusaraiva
 *
 * Created on 8 de dezembro de 2020, 21:40
 */

#ifndef IMPERIO_H
#define IMPERIO_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#include "Territorio.h"
#include "Tecnologia.h"

class Imperio
{
    vector<Territorio> territorios_imperio;
    Tecnologia tecnologias;

    // armazem -> produtos
    // cofre -> ouros
    unsigned int armazem, cofre, forca_militar;
    unsigned int capacidade_armazem, capacidade_cofre, capacidade_militar;
    
    int pontosConquista = 0;
    bool conquistaQualquer = false;
    bool trocaOuro = false;
    bool perdido = false;
public:

    Imperio();
    Imperio(int& arm, int& cof, int& f_mil, int& c_arm, int& c_cof, int& c_mil);
    
    void evento_aleatorio(string nome, int fase);
    void evento_recursoAbandonado(string recurso);
    void evento_invasao(int fase);
    void evento_aliancaDiplomatica();
    void produzMateriais();
    
    string getAsString() const;
    int get_forcaMilitar() const;
    int get_capacidadeForcaMilitar() const;
    int get_tamanho() const;
    int get_pontosConquista() const;
    void adiciona_pontosConquista();
    bool imperioPerdido() const;
    
    void adiciona_ouro(int maisOuro);
    void adiciona_produtos(int maisProdutos);
    void adiciona_militar(int maisMilitar);
    
    bool aumenta_militar();
    bool aumenta_produtos();
    bool aumenta_ouro();
    
    void mostra_tecnologias() const;
    int get_nTecnologias() const;
    bool adiciona_tecnologia(string nome);
    
    void set_forcaMilitar(int novaForca);
    void set_capacidadeForcaMilitar(int novaCapacidade);
    void addTerritorio(Territorio &terr);
    void removeTerritorio(string nome);
};

#endif /* IMPERIO_H */

