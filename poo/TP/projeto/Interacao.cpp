/* 
 * File:   INTERACAO.cpp
 * Author: rafaeljesusaraiva
 *
 * Created on 28 de dezembro de 2020, 19:25
 */

#include "Interacao.h"

Interacao::Interacao() {
    cout << endl << "Compilado no Netbeans para Mac" << endl;
    cout << "Em falta: " << endl;
    cout << "\t- Mudanca de criacao dos territorios ao longo do jogo" << endl;
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
        bool sucessoComando = false;
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
        if (com_args[0].compare("conquista") == 0) {
            if ((this->mundo).verifica_conquista(com_args[1]))
                (this->mundo).adiciona_conquista(com_args[1]);
            sucessoComando = true;
        }
        
        /* 
         * Opcao Passa
         *   <passa>
         * - Executa eventos aleatorios e continua
         */
        if (com_args[0].compare("passa") == 0) {
            this->proxRonda(turno);
            continue;
        }
        
        /* 
         * Opcao Aumentar Forca Militar (1x por turno)
         *   <maismilitar>
         */
        if (com_args[0].compare("maismilitar") == 0) {
            if (this->flag_militar == false) {
                if ((this->mundo).aumenta_militar())
                    this->flag_militar = true;
                else
                    cout << "Nao foi possivel adquirir militares." << endl;
            } else {
                cout << "Forca militar ja aumentada esta ronda" << endl;
            }
            turno--;
            continue;
        }
        
        /* 
         * Opcao Aumentar Tecnologia (1x por turno)
         *   <adquire *tipo*>
         */
        if (com_args[0].compare("adquire") == 0) {
            if (this->flag_tecnologia == false) {
                cout << " Cheguei a flag";
                if ((this->mundo).adiciona_tecnologia(com_args[1]))
                    this->flag_tecnologia = true;
                else
                    cout << "Nao foi possivel adquirir tecnologia." << endl;
            } else {
                cout << "Teecnologia ja adquirida esta ronda" << endl;
            }
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
        if (com_args[0].compare("maisouro") == 0){
            (this->mundo).aumenta_ouro();
            sucessoComando = true;
        }
        
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
            turno--;
            continue;
        }
        
        /* 
         * Opcao Max Militar
         *   <maxMilitar>
         */
        if (com_args[0].compare("maxMilitar") == 0){
            (this->mundo).adiciona_maxForcaMilitar();
            sucessoComando = true;
        }
        
        /* 
         * Forca evento
         *   <fevento *nome*>
         * Executa evento e passa à frente aleatórios
         */
        if (com_args[0].compare("fevento") == 0) {
            (this->mundo).executar_evento(com_args[1], turno);
            continue;
        }
            
        if (this->mundo.imperioPerdido()) {
            break;
        }
        
        /* 
         * Opcao DEV para sair
         *   <sair>
         */
        if (com_args[0].compare("sair") == 0)
            break;
        
        if (sucessoComando)
            this->proxRonda(turno);
        else {
            cout << "Comando Invalido!" << endl;
            turno--;
            continue;
        }
        
        
    }
}

void Interacao::proxRonda(int turno) { 
    (this->mundo).executar_evento("random", turno);
    (this->mundo).produzMateriais();
    this->flag_militar = false;
    this->flag_tecnologia = false;
}

void Interacao::mostra_ajuda_jogo() {
    cout << endl;
    cout << "AJUDA:" << endl;
    cout << "\t> conquista <territorio> (tenta conquistar o territorio)" << endl;
    cout << "\t> passa (avanca o turno)" << endl;
    cout << "\t> maismilitar (+1 militar ; -1 produto & -1 ouro)" << endl;
    cout << "\t> adquire <tipo> (adquire o tipo de tecnologia)" << endl;
    cout << "\t> maisprod (+1 produto ; -2 ouro)" << endl;
    cout << "\t> maisouro (+1 ouro ; -2 produto)" << endl;
    cout << "\t> lista (lista todos os territorios)" << endl;
    cout << "\t> lista <territorio> (lista info do territorio)" << endl;
    cout << "\t> maxMilitar (define forca e cap. militar para 20 [DEBUG])" << endl;
    cout << "\t> fevento <evento> (forca evento)" << endl;
    cout << "\t> sair (sai antecipadamente do jogo [DEBUG])" << endl;
}

/*
 *  Calcula pontuacao final do jogo
 */
void Interacao::mostraPontuacao() {
    int pontuacao = 0;
    int conquistaImperio = mundo.pontosConquistaImperio();
    int obtemTecnologia = this->mundo.obtem_tecnologiaImperio();
    int bonusCientifico = 0;
    if (this->mundo.obtem_tecnologiaImperio() >= 5) 
        bonusCientifico += 1;
    int overlord = 0;
    if (this->mundo.total_territorios_imperio() == this->mundo.total_territorios_mundo()) 
        overlord += 3;
    
    // pontos conquista
    pontuacao += conquistaImperio;
    // pontos tecnologia
    pontuacao += obtemTecnologia;
    // bonus cientifico (>5 tecnologia)
    pontuacao += bonusCientifico;
    // bonus imperador supremo
    pontuacao += overlord;
    
    cout << "Obteve " << pontuacao << " pontos!" << endl;
    cout << "\tBonus Conquistas: +" << conquistaImperio << endl;
    cout << "\tBonus Tecnologias: +" << obtemTecnologia << endl;
    cout << "\tBonus Cientifico: +" << bonusCientifico << endl;
    cout << "\tBonus Overlord: +" << overlord << endl << endl;
    
}

void Interacao::resumo() {
    // Limpar ecra
    cout << string( 100, '\n' );
    this->mostraPontuacao();
    // apresentar resumo
    cout << "Resumo deste Jogo:" << endl;
    this->mundo.lista_imperio();
}

void Interacao::fim() {
    cout << endl << endl;
    cout << "\tFim do Jogo!" << endl << endl;
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
