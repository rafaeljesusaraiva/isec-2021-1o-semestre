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
//#include "Tecnologia.h"

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
    
    Mundo mundo;
    
    cout << ">> MODO CONFIGURACAO" << endl << endl;
    do {
        cout << "\tInserir nova configuracao? [sim/nao]" << endl;
        cout << "\t> ";
        string continuar, comando;
        cin >> continuar;
        
        if (continuar.compare("nao") == 0)
            break;
        
        if (continuar.compare("ajuda") == 0) {
            cout << "AJUDA:" << endl;
            cout << "\t> cria <territorio> <quantidade>" << endl;
            cout << "\t> carrega <nome ficheiro>" << endl;
            continue;
        }
        
        if (continuar.compare("sim") != 0) {
            cout << "\tComando Invalido!" << endl;
            continue;
        }
        
        cout << "> Comando configuracao: ";
        cin.ignore();
        getline(cin, comando);

        vector<string> com_args;
        separa_args(comando, com_args);

        if (com_args[0].compare("cria") == 0) {
            if (com_args.size() < 3) {
                cout << "ERRO > Numero de argumentos em falta !" << endl << endl;
                continue;
            }
            if (!mundo.verifica_numero(com_args[2])) {
                cout << "ERRO > Numero invalido !" << endl << endl;
                continue;
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
                cout << "ERRO > Lista com numero de argumentos invalido!" << endl << endl;
        }
    } while (true);
    
    cout << endl;
    cin.ignore();
    
    for (int turno = 1; turno <= 12; turno++) {
        string comando = "";
        do {
            cout << "> Comando Turno [" << turno << "]: ";
            getline(cin, comando, '\n');
            if (comando.compare("ajuda") == 0) {
                cout << endl;
                cout << "AJUDA:" << endl;
                cout << "\t> conquista <territorio> (tenta conquistar o territorio)" << endl;
                cout << "\t> lista (lista todos os territorios)" << endl;
                cout << "\t> lista <territorio> (lista info do territorio)" << endl;
                cout << "\t> maxMilitar (define forca e cap. militar para 20 [DEBUG])" << endl;
                cout << "\t> sair (sai antecipadamente do jogo [DEBUG])" << endl;
            }
        } while (comando == "" || comando.compare("ajuda") == 0);
            
        vector<string> com_args;
        separa_args(comando, com_args);
        
        // cout << "DEBUG > Inserido '" << comando << "'" << endl;
        
        if (com_args[0].compare("conquista") == 0)
            if (mundo.verifica_conquista(com_args[1]))
                mundo.adiciona_conquista(com_args[1]);
        
        if (com_args[0].compare("lista") == 0)
            if (com_args.size() == 1)
                 mundo.lista_territorios();
            else if (com_args.size() == 2)
                 mundo.lista_territorios(com_args[1]);
            else 
                cout << "Lista com numero de argumentos invalido !" << endl << endl;
        
        if (com_args[0].compare("maxMilitar") == 0)
            mundo.adiciona_maxForcaMilitar();
            
        if (com_args[0].compare("sair") == 0)
            break;
    }
    return 0;
}
