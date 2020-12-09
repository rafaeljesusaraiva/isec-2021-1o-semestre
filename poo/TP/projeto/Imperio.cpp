/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Imperio.cpp
 * Author: rafaeljesusaraiva
 * 
 * Created on 8 de dezembro de 2020, 21:40
 */

#include "Imperio.h"

Imperio::Imperio() {
    string nomeInicial = "Territorio Inicial";
    int resistenciaInicial = 9, criaProdutoInicial = 1, criaOuroInicial = 1;
    Territorio territorio_inicial(nomeInicial, resistenciaInicial, criaProdutoInicial, criaOuroInicial);
    territorios_imperio.push_back(territorio_inicial);
    armazem = 0;
    cofre = 0;
    forca_militar = 0;
    capacidade_armazem = 3;
    capacidade_cofre = 3;
    capacidade_militar = 3;
}


Imperio::Imperio(int& in_armazem, int& in_cofre, int& in_forcaMilitar, int& in_capacidadeArmazem, int& in_capacidadeCofre, int& in_capacidadeMilitar):
    armazem(in_armazem), cofre(in_cofre), forca_militar(in_forcaMilitar), 
    capacidade_armazem(in_capacidadeArmazem), capacidade_cofre(in_capacidadeCofre), 
    capacidade_militar(in_capacidadeMilitar) {
    string nomeInicial = "Territorio Inicial";
    int resistenciaInicial = 9, criaProdutoInicial = 1, criaOuroInicial = 1;
    Territorio territorio_inicial(nomeInicial, resistenciaInicial, criaProdutoInicial, criaOuroInicial);
    territorios_imperio.push_back(territorio_inicial);
}


string Imperio::getAsString() const {
    ostringstream os;
    os << ">> Territorios do Imperio" << endl;
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

int Imperio::get_forcaMilitar() const { return forca_militar; }
int Imperio::get_capacidadeForcaMilitar() const { return capacidade_militar; }
void Imperio::set_forcaMilitar(int novaForca) { forca_militar = novaForca; }
void Imperio::set_capacidadeForcaMilitar(int novaCapacidade) { capacidade_militar = novaCapacidade; }
void Imperio::addTerritorio(Territorio &terr) { territorios_imperio.push_back(terr); }

