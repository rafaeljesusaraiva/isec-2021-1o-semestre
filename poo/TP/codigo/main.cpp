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
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <time.h>

#include "Mundo.h"
#include "Imperio.h"
#include "Territorio.h"
//#include "TECNOLOGIA.h"

using namespace std;

/*
 *  Separa comando em vetor de argumentos
 */
vector<string> separa_args(string comando, vector<string>& args) {
    string arg;
    istringstream ss(comando);
    while (ss >> arg)
        args.push_back(arg);
    return args;
}


int main() {
    // Inicialização randomizer
    srand(time(NULL));
    
    MUNDO mundo;
    //IMPERIO teste = mundo.i;
    
    cout << ">> MODO CONFIGURACAO" << endl;
    do {
        cout << "\tInserir nova configuracao? [sim/nao]" << endl;
        cout << "\t> ";
        string continuar, comando;
        cin >> continuar;
        if (continuar.compare("nao") == 0)
            break;
        
        cout << "> Comando: ";
        cin.ignore();
        getline(cin, comando);

        vector<string> com_args;
        separa_args(comando, com_args);

        if (com_args[0].compare("cria") == 0) {
            if (com_args.size() < 3) {
                cout << "ERRO > Numero de argumentos em falta !" << endl;
                break;
            }
            if (!mundo.verifica_numero(com_args[2])) {
                cout << "ERRO > Numero invalido !" << endl;
                break;
            }
            int num = stoi(com_args[2]);
            string tipo = com_args[1];
            mundo.insere_territorios(tipo, num);
        } else if (com_args[0] == "carrega") {
            mundo.carrega_fich_territorios(com_args[1]);
        }
        else if (com_args[0] == "lista") {
            if (com_args.size() == 1) {
                mundo.lista_territorios();
            } else if (com_args.size() == 2) {
                mundo.lista_territorios(com_args[1]);
            } else
                cout << "ERRO > Lista com numero de argumentos invalido!" << endl;
        }
    } while (true);
    
    cout << endl;
    cin.ignore();
    
    for (int turno = 1; turno <= 12; turno++) {
        string comando;
        cout << "> Comando: ";
        getline(cin, comando, '\n');
   
        vector<string> com_args;
        separa_args(comando, com_args);
        
        cout << "DEBUG > Inserido '" << comando << "'" << endl;
        
        if (com_args[0] == "conquista")
            if (mundo.verifica_conquista(com_args[1]))
                mundo.adiciona_conquista(com_args[1]);
        
        if (com_args[0] == "lista")
            if (com_args.size() == 1)
                 mundo.lista_territorios();
            else if (com_args.size() == 2)
                 mundo.lista_territorios(com_args[1]);
            else 
                cout << "Lista com numero de argumentos invalido !" << endl;
    }
    return 0;
}
