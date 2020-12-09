/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IMPERIO.cpp
 * Author: rafaeljesusaraiva
 * 
 * Created on 8 de dezembro de 2020, 21:40
 */

#include "Imperio.h"

IMPERIO::IMPERIO() {
    string nomeInicial = "Territorio Inicial";
    int resistenciaInicial = 9, criaProdutoInicial = 1, criaOuroInicial = 1;
    TERRITORIO territorio_inicial(nomeInicial, resistenciaInicial, criaProdutoInicial, criaOuroInicial);
    territorios_imperio.push_back(territorio_inicial);
    armazem = 0;
    cofre = 0;
    forca_militar = 0;
    capacidade_armazem = 3;
    capacidade_cofre = 3;
    capacidade_militar = 3;
}


IMPERIO::IMPERIO(int& in_armazem, int& in_cofre, int& in_forcaMilitar, int& in_capacidadeArmazem, int& in_capacidadeCofre, int& in_capacidadeMilitar):
    armazem(in_armazem), cofre(in_cofre), forca_militar(in_forcaMilitar), 
    capacidade_armazem(in_capacidadeArmazem), capacidade_cofre(in_capacidadeCofre), 
    capacidade_militar(in_capacidadeMilitar) {
    string nomeInicial = "Territorio Inicial";
    int resistenciaInicial = 9, criaProdutoInicial = 1, criaOuroInicial = 1;
    TERRITORIO territorio_inicial(nomeInicial, resistenciaInicial, criaProdutoInicial, criaOuroInicial);
    territorios_imperio.push_back(territorio_inicial);
}


string IMPERIO::getAsString() const {
    ostringstream os;
    os << ">> Territorios" << endl;
    os << "\t";
    for (auto t : territorios_imperio)
        os << t.get_nome() << "  ";
    os << endl << endl << ">> Detalhes Imperio" << endl;
    // Ignorar Tecnologias
    os << "\tProdutos em Armazem: " << armazem << endl;
    os << "\tCapacidade do Armazem : " << capacidade_armazem << endl;
    os << "\tOuro no Cofre: " << cofre << endl;
    os << "\tCapacidade do cofre : " << capacidade_cofre << endl;
    os << "\tForca Militar: " << forca_militar << endl;
    os << "\tCapacidade Militar: " << capacidade_militar << endl;
    return os.str();
}

int IMPERIO::getFMilitar() const { return forca_militar; }

void IMPERIO::setFMilitar(int FMilReduzida) { forca_militar = FMilReduzida; }

void IMPERIO::addTerritorio(TERRITORIO &terr) { territorios_imperio.push_back(terr); }

