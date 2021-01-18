/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tecnologia.cpp
 * Author: rafaeljesusaraiva
 * 
 * Created on 8 de dezembro de 2020, 21:39
 */

#include "Tecnologia.h"

bool Tecnologia::adiciona_tecnologia(string tipo) {
    bool check = false;
    for (size_t i=0; i<this->tipos.size(); i++)
        if (this->tipos[i].compare(tipo) == 0)
            check = true;
    if (check) {
        this->adquiridas.push_back(tipo);
        return true;
    } else {
        cout << "[Erro] Tipo de tecnologia nao existente. (" << tipo << ")" <<endl;
        return false;
    } 
}

void Tecnologia::mostra_tecnologias() const {
    cout << "Tecnologias disponiveis: ";
    if (this->adquiridas.size() == 0)
        cout << "Nenhuma" << endl;
    else {
        cout << endl;
        for (size_t i=0; i<this->adquiridas.size(); i++)
            cout << "\t " << this->adquiridas[i] << endl;
    }
}

int Tecnologia::get_nTecnologias() const {
    return this->adquiridas.size();
}