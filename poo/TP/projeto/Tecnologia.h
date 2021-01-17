/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tecnologia.h
 * Author: rafaeljesusaraiva
 *
 * Created on 8 de dezembro de 2020, 21:39
 */

#ifndef TECNOLOGIA_H
#define TECNOLOGIA_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Tecnologia {
    vector<string> tipos = { "dronesMilitares", "misseisTeleguiados", "defesasTerritoriais", "bolsaDeValores", "bancoCentral"};
    vector<string> adquiridas;
public:
    //Tecnologia();
    bool adiciona_tecnologia(string tipo);
    void mostra_tecnologias() const;
    int get_nTecnologias() const;
};

#endif /* TECNOLOGIA_H */

