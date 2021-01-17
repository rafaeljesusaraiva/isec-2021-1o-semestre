/* 
 * File:   INTERACAO.cpp
 * Author: rafaeljesusaraiva
 *
 * Created on 28 de dezembro de 2020, 19:25
 */

#include "Interacao.h"

Interacao::Interacao() {
    cout << ">> MODO CONFIGURACAO" << endl << endl;
    do {
        cout << "\tInserir nova configuracao? [sim/nao]" << endl;
        cout << "\t> ";
        string continuar, comando;
        cin >> continuar;
        
        if (continuar.compare("nao") == 0)
            break;
        
        if (continuar.compare("ajuda") == 0) {
            this->mostra_ajuda_configuracao();
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
        this->separa_args(comando, com_args);

        if (com_args[0].compare("cria") == 0) {
            if (this->configuracao_cria(com_args) == 1)
                continue;
        } else if (com_args[0] == "carrega") {
            (this->mundo).carrega_fich_territorios(com_args[1]);
        } else if (com_args[0] == "lista") {
            this->configuracao_lista(com_args);
        } else if (com_args[0] == "ajuda") {
            this->mostra_ajuda_configuracao();
        } else continue;
    } while (true);
    
    cout << endl;
}

int Interacao::configuracao_cria(vector<string> com_args) {
    if (com_args.size() < 3) {
        cout << "ERRO > Numero de argumentos em falta !" << endl << endl;
        return 1;
    }
    if (!(this->mundo).verifica_numero(com_args[2])) {
        cout << "ERRO > Numero invalido !" << endl << endl;
        return 1;
    }
    int num = stoi(com_args[2]);
    string tipo = com_args[1];
    (this->mundo).insere_territorios(tipo, num);
    return 0;
}

void Interacao::configuracao_lista(vector<string> com_args) {
    if (com_args.size() == 1) {
        (this->mundo).lista_territorios();
    } else if (com_args.size() == 2) {
        (this->mundo).lista_territorios(com_args[1]);
    } else
        cout << "ERRO > Lista com numero de argumentos invalido!" << endl << endl;
}

void Interacao::mostra_ajuda_configuracao() {
    cout << "AJUDA:" << endl;
    cout << "\t> cria <territorio> <quantidade>" << endl;
    cout << "\t> carrega <nome ficheiro>" << endl;
}

void Interacao::menu() {
    cin.ignore();
    
    for (int turno = 1; turno <= 12; turno++) {
        string comando = "";
        do {
            cout << "> Comando Turno [" << turno << "]: ";
            getline(cin, comando, '\n');
            if (comando.compare("ajuda") == 0)
                this->mostra_ajuda_jogo();
        } while (comando == "" || comando.compare("ajuda") == 0);
            
        vector<string> com_args;
        this->separa_args(comando, com_args);
        // cout << "DEBUG > Inserido '" << comando << "'" << endl;
        
        /* 
         * Opcao Conquista
         *   <conquista>
         */
        if (com_args[0].compare("conquista") == 0)
            if ((this->mundo).verifica_conquista(com_args[1]))
                (this->mundo).adiciona_conquista(com_args[1]);
        
        /* 
         * Opcao Passa
         *   <passa>
         * - Executa eventos aleatorios e continua
         */
        if (com_args[0].compare("passa") == 0) {
            continue;
        }
        
        /* 
         * Opcao Aumentar Forca Militar (1x por turno)
         *   <maismilitar>
         */
        if (com_args[0].compare("maismilitar") == 0) {
            (this->mundo).aumenta_militar();
            turno--;
            continue;
        }
        
        /* 
         * Opcao Aumentar Tecnologia (1x por turno)
         *   <adquire>
         */
        if (com_args[0].compare("adquire") == 0) {
            (this->mundo).aumenta_tecnologia();
            turno--;
            continue;
        }
            
        /* 
         * Opcao Produz produtos (+1 prod ; -2 ouro)
         *   <maisprod>
         */
        if (com_args[0].compare("maisprod") == 0) {
            (this->mundo).aumenta_produtos();
            turno--;
            continue;
        }
            
        /* 
         * Opcao Produz ouro (+1 ouro ; -2 prod)
         *   <maisouro>
         */
        if (com_args[0].compare("maisouro") == 0) 
            (this->mundo).aumenta_ouro();
        
        /* 
         * Opcao Lista
         *   <lista>
         *   <lista *territorio*>
         */
        if (com_args[0].compare("lista") == 0) {
            if (com_args.size() == 1){
                 (this->mundo).lista_territorios();
            } else if (com_args.size() == 2) {
                 (this->mundo).lista_territorios(com_args[1]);
            } else {
                cout << "Lista com numero de argumentos invalido !";
                cout << endl << endl;
            }
        }
        
        /* 
         * Opcao Max Militar
         *   <maxMilitar>
         */
        if (com_args[0].compare("maxMilitar") == 0)
            (this->mundo).adiciona_maxForcaMilitar();
        
        /* 
         * Forca evento
         *   <fevento *nome*>
         * Executa evento e passa à frente aleatórios
         */
        if (com_args[0].compare("fevento") == 0)
            (this->mundo).executar_evento(com_args[1], turno);
        else
            (this->mundo).executar_evento("random", turno);
            
        /* 
         * Opcao DEV para sair
         *   <sair>
         */
        if (com_args[0].compare("sair") == 0)
            break;
    }
}

void Interacao::mostra_ajuda_jogo() {
    cout << endl;
    cout << "AJUDA:" << endl;
    cout << "\t> conquista <territorio> (tenta conquistar o territorio)" << endl;
    cout << "\t> lista (lista todos os territorios)" << endl;
    cout << "\t> lista <territorio> (lista info do territorio)" << endl;
    cout << "\t> maxMilitar (define forca e cap. militar para 20 [DEBUG])" << endl;
    cout << "\t> sair (sai antecipadamente do jogo [DEBUG])" << endl;
}

/*
 *  Separa comando em vetor de argumentos
 */
vector<string> Interacao::separa_args(string comando, vector<string>& args) {
    string arg;
    istringstream ss(comando);
    if (comando.empty())
        return args;
    while (ss >> arg)
        args.push_back(arg);
    return args;
}
