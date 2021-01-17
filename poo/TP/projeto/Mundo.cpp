/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MUNDO.cpp
 * Author: rafaeljesusaraiva
 * 
 * Created on 8 de dezembro de 2020, 21:38
 */

#include "Mundo.h"
#include <time.h>


void Mundo::insere_territorios(string tipo, int num) {
    bool existe = false;
    int resistencia = 5, cria_produto = 1, cria_ouro = 1;
    for (int i = 0; i < num; i++) {
        for (unsigned int j = 0; j < tipos.size(); j++) {
            if (tipos[j] == tipo) {
                existe = true;
                enumeracao[j]++;
                string nome = tipo + to_string(enumeracao[j]);
                // Verificacao se territorio foi inserido
                Territorio novo_territorio(nome, resistencia, cria_produto, cria_ouro);
                cout << novo_territorio.getAsString() << endl;
                territorios.push_back(novo_territorio);
            }
        }
    }
    if (!existe)
        cout << "Territorio nao existe !" << endl;
}

void Mundo::remove_territorio(string nome) {
    int posTerritorio = -1;
    for (size_t i=0; i < this->territorios.size(); i++) {
        if (this->territorios[i].nome == nome) {
            posTerritorio = i;
            break;
        }
    }
    if (posTerritorio == -1) {
        cout << "[Erro] Nenhum territorio com o nome pedido!" << endl;
        return;
    } else {
        cout << ">> Territorio '" << this->territorios[posTerritorio].nome << "' removido do Mundo!" << endl;
        if (posTerritorio > 0) posTerritorio -= 1;
        this->territorios.erase(this->territorios.begin() + posTerritorio);
    }
}

bool Mundo::verifica_numero(string num) const{
    for (unsigned int i = 0; i < num.length(); i++)
        if (num[i] < '0' || num[i] > '9') 
            return false;
    return true;
}

/*
 *  Carrega Territorios no Mundo por ficheiro
 */
void Mundo::carrega_fich_territorios(string nome_ficheiro){
    ifstream ifs(nome_ficheiro);
    string tipo, num;
    if (ifs.fail()) {
        cout << "ERRO > Nome do ficheiro invalido !" << endl;
        return;
    }
    while (ifs >> tipo >> num) {
        if (!verifica_numero(num)) {
            cout << "ERRO > Numero invalido no ficheiro !" << endl;
            continue; // passa a proxima iteracao do ciclo
        }
        else if (ifs.fail()) {
            ifs.clear();
            cout << "ERRO > Ocorreu um erro ao ler o ficheiro !" << endl;
        }
        else 
            insere_territorios(tipo, stoi(num));
    }
}

/*
 *  Lista Território no Mundo (especifico)
 *      ex.: lista <nome territorio>
 */
void Mundo::lista_territorios(string terr) const{
    bool existe = false;
    for (auto t : territorios) {
        string nome_t = t.get_nome();
        if (nome_t == terr) {
            cout << t.getAsString() << endl;
            existe = true;
        }
    }
    if (!existe) 
        cout << "Territorio nao existe!" << endl;
}

/*
 *  Lista todos os Territórios no Mundo
 *      ex.: lista
 */
void Mundo::lista_territorios() const{
    // lista
    cout << ">> Territorios do mundo" << endl;
    for (auto t : territorios) {
        cout << t.getAsString() << endl;
    }
    cout << imperio.getAsString() << endl;

}

/*
 *  Lista todos os Territórios no Mundo
 *      ex.: lista
 */
void Mundo::lista_imperio() const {
    cout << imperio.getAsString() << endl;
}

/*
 *  Obtem fator de sorte em inteiro
 */
int fator_sorte() { return (rand() % 6) + 1; }

/*
 *  Verifica possibilidade de conquista
 */
bool Mundo::verifica_conquista(string nome_t) {
    bool possivel = false;
    cout << "\tA tentar conquistar " << nome_t << endl;
    for (auto t : territorios)
        if (nome_t == t.get_nome())
            if (imperio.get_forcaMilitar() + fator_sorte() >= t.get_resistencia()) {
                possivel = true;
                cout << "\tPossivel conquista de " << nome_t << endl;
            }
    if (!possivel) {
        if (imperio.get_forcaMilitar() != 0) {
            imperio.set_forcaMilitar(imperio.get_forcaMilitar() - 1);
        }
    }
    
    return possivel;
}

/*
 * Adiciona um Territorio conquistado ao Mundo
 */
void Mundo::adiciona_conquista(string territorio) {
    for (auto t : territorios) {
        if (territorio == t.get_nome()) {
            imperio.addTerritorio(t);
            imperio.adiciona_pontosConquista();
            cout << "\tConquista de " << territorio << " feita!" << endl;
        }
    }
}

void Mundo::executar_evento(string nome, int fase) {
    imperio.evento_aleatorio(nome, fase);
}

bool Mundo::aumenta_militar() {
    return this->imperio.aumenta_militar();
}

bool Mundo::adiciona_tecnologia(string nome) {
    return this->imperio.adiciona_tecnologia(nome);
}

bool Mundo::aumenta_produtos() {
    return this->imperio.aumenta_produtos();
}

bool Mundo::aumenta_ouro() {
    return this->imperio.aumenta_ouro();
}

bool Mundo::imperioPerdido() const { 
    return this->imperio.imperioPerdido(); 
}

int Mundo::tamanhoImperio() const {
    return this->imperio.get_tamanho();
}

int Mundo::pontosConquistaImperio() const {
    return this->imperio.get_pontosConquista();
}

int Mundo::obtem_tecnologiaImperio() const {
    return this->imperio.get_nTecnologias();
}

void Mundo::produzMateriais() {
    this->imperio.produzMateriais();
}

void Mundo::adiciona_maxForcaMilitar() {
    imperio.set_capacidadeForcaMilitar(20);
    imperio.set_forcaMilitar(imperio.get_capacidadeForcaMilitar());
    cout << "[DEV] Forca militar maximizada (" << imperio.get_forcaMilitar() << "/" << imperio.get_capacidadeForcaMilitar() << ") !" << endl;
}