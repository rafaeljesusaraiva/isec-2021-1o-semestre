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


void MUNDO::insere_territorios(string tipo, int num) {
    bool existe = false;
    int resistencia = 100, cria_produto = 1, cria_ouro = 1;
    for (int i = 0; i < num; i++) {
        for (unsigned int j = 0; j < tipos.size(); j++) {
            if (tipos[j] == tipo) {
                existe = true;
                enumeracao[j]++;
                string nome = tipo + to_string(enumeracao[j]);
                TERRITORIO novo_territorio(nome, resistencia, cria_produto, cria_ouro);
                cout << novo_territorio.getAsString() << endl;
                territorios.push_back(novo_territorio);
            }
        }
    }
    if (!existe)
        cout << "Territorio nao existe !" << endl;
}

bool MUNDO::verifica_numero(string num) const{
    for (unsigned int i = 0; i < num.length(); i++)
        if (num[i] < '0' || num[i] > '9') 
            return false;
    return true;
}

/*
 *  Carrega Territorios no Mundo por ficheiro
 */
void MUNDO::carrega_fich_territorios(string nome_ficheiro){
    ifstream ifs(nome_ficheiro);
    string tipo, num;
    if (ifs.fail()) {
        cout << "Nome do ficheiro invalido !" << endl;
        return;
    }
    while (ifs >> tipo >> num) {
        if (!verifica_numero(num)) {
            cout << "Numero invalido no ficheiro !" << endl;
            continue; // passa a proxima iteracao do ciclo
        }
        else if (ifs.fail()) {
            ifs.clear();
            cout << "Ocorreu um erro ao ler o ficheiro !" << endl;
        }
        else 
            insere_territorios(tipo, stoi(num));
    }
}

/*
 *  Lista Territórios no Mundo (especifico)
 *      ex.: lista <nome territorio>
 */
void MUNDO::lista_territorios(string terr) const{
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
void MUNDO::lista_territorios() const{
    // lista
    cout << "--- Territorios do mundo ---" << endl;
    for (auto t : territorios) {
        cout << t.getAsString() << endl;
    }
    cout << i.getAsString() << endl;

}

/*
 *  Obtem fator de sorte em inteiro
 */
int fator_sorte() { return (rand() % 6) + 1; }

/*
 *  Verifica possibilidade de conquista
 */
bool MUNDO::verifica_conquista(string nome_t) {
    bool possivel = false;
    for (auto t : territorios)
        if (nome_t == t.get_nome())
            if (i.getFMilitar() + fator_sorte() >= t.get_resistencia()) 
                possivel = true;
    if (!possivel) {
        if (i.getFMilitar() != 0) {
            i.setFMilitar(i.getFMilitar() - 1);
        }
    }
    return possivel;
}

/*
 * Adiciona um Territorio conquistado ao Mundo
 */
void MUNDO::adiciona_conquista(string terr) {
    for (auto t : territorios) {
        if (terr == t.get_nome()) {
            i.addTerritorio(t);
        }
    }
}


