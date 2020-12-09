/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TERRITORIO.cpp
 * Author: rafaeljesusaraiva
 * 
 * Created on 8 de dezembro de 2020, 21:39
 */

#include "Territorio.h"

TERRITORIO::TERRITORIO(const string& in_nome, const int& in_resistencia, int& in_criaProduto, int& in_criaOuro):
    nome(in_nome), resistencia(in_resistencia), cria_produto(in_criaProduto), cria_ouro(in_criaOuro) {}


string TERRITORIO::getAsString() const {
    ostringstream os;
    os << "\tNome Territorio : " << nome << endl;
    os << "\tResistencia : " << resistencia << endl;
    os << "\tCria " << cria_produto << " de produto e " << cria_ouro << " de ouro por turno" << endl;
    return os.str();
}


string TERRITORIO::get_nome() const { return nome; }

int TERRITORIO::get_resistencia() const { return resistencia; }
