/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rafaeljesusaraiva
 *
 * Created on 8 de dezembro de 2020, 21:25
 */

#include "Interacao.h"

int main() {
    // Inicialização randomizer
    srand(time(NULL));

    // Cria o jogo e ativa a configuracao
    Interacao *Jogo = new Interacao();
    
    // Inicia o Jogo
    Jogo->menu();
    
    // Termino do Jogo
    Jogo->resumo();
    Jogo->fim();

    return 0;
}
