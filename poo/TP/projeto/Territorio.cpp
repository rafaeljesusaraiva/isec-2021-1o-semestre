/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Territorio.cpp
 * Author: rafaeljesusaraiva
 * 
 * Created on 8 de dezembro de 2020, 21:39
 */

#include "Territorio.h"

Territorio::Territorio(const string& in_nome, string& tipo) : nome(in_nome) {
    // resistencia(in_resistencia)
    // cria_produto(in_criaProduto)
    //  cria_ouro(in_criaOuro)
    bool flag = false;
    if (tipo.compare("territorioInicial") == 0) {
        this->resistencia = 9;
        this->cria_produto = 1;
        this->cria_ouro = 1;
    } else {
        for (size_t i=0; i<this->default_continente.size(); i++) {
            if (this->default_continente[i].compare(tipo) == 0) {
                this->tipo = this->default_continente_nome[i];
                this->resistencia = this->default_continente_resistencia[i];
                this->cria_produto = this->default_continente_produto[i];
                this->cria_ouro = this->default_continente_ouro[i];
                flag = true;
                break;
            }
        }
        if (flag == false)
            for (size_t i=0; i<this->default_ilha.size(); i++) {
                if (this->default_ilha[i].compare(tipo) == 0) {
                    this->tipo = this->default_ilha_nome[i];
                    this->resistencia = this->default_ilha_resistencia[i];
                    this->cria_produto = this->default_ilha_produto[i];
                    this->cria_ouro = this->default_ilha_ouro[i];
                    flag = true;
                    break;
                }
            }
        if (flag == false)
            throw("Erro");
    }
    
}


string Territorio::getAsString() const {
    ostringstream os;
    os << "\tNome Territorio : " << nome << endl;
    os << "\tResistencia : " << resistencia << endl;
    os << "\tCria " << cria_produto << " de produto e " << cria_ouro << " de ouro por turno" << endl;
    return os.str();
}


string Territorio::get_nome() const { return nome; }
int Territorio::get_resistencia() const { return resistencia; }
int Territorio::get_criaOuro() const { return cria_ouro; }
int Territorio::get_criaProduto() const { return cria_produto; }