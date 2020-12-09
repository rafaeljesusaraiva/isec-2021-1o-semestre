/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IMPERIO.h
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

class IMPERIO
{
    vector<TERRITORIO> territorios_imperio;
    vector<TECNOLOGIA> tecnologias;

    unsigned int armazem, cofre, forca_militar;
    unsigned int capacidade_armazem, capacidade_cofre, capacidade_militar;

public:

    IMPERIO();
    IMPERIO(int& arm, int& cof, int& f_mil, int& c_arm, int& c_cof, int& c_mil);
    string getAsString() const;
    int getFMilitar() const;
    void setFMilitar(int FMilReduzida);
    void addTerritorio(TERRITORIO &terr);
};

#endif /* IMPERIO_H */

