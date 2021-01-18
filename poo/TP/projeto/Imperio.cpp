/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Imperio.cpp
 * Author: rafaeljesusaraiva
 * 
 * Created on 8 de dezembro de 2020, 21:40
 */

#include "Imperio.h"

Imperio::Imperio() {
    string nomeInicial = "Territorio Inicial";
    string tipo = "territorioInicial";
    Territorio territorio_inicial(nomeInicial, tipo);
    territorios_imperio.push_back(territorio_inicial);
    armazem = 0;
    cofre = 0;
    forca_militar = 0;
    capacidade_armazem = 3;
    capacidade_cofre = 3;
    capacidade_militar = 3;
}


Imperio::Imperio(int& in_armazem, int& in_cofre, int& in_forcaMilitar, int& in_capacidadeArmazem, int& in_capacidadeCofre, int& in_capacidadeMilitar):
    armazem(in_armazem), cofre(in_cofre), forca_militar(in_forcaMilitar), 
    capacidade_armazem(in_capacidadeArmazem), capacidade_cofre(in_capacidadeCofre), 
    capacidade_militar(in_capacidadeMilitar) {
    string nomeInicial = "Territorio Inicial";
    string tipo = "territorioInicial";
    Territorio territorio_inicial(nomeInicial, tipo);
    territorios_imperio.push_back(territorio_inicial);
}

/*
 * Executa um evento aleatorio
 */
void Imperio::evento_aleatorio(string nome, int fase) {
    /* 
    * Evento Aleatorio (1-4)
    */
    int random = rand() % 4 + 1;
    if (nome.compare("random") == 0)
        switch (random) {
            /*   - Recurso Abandonado    */
            case 1:
                if (fase < 6)
                    this->evento_recursoAbandonado("produto");
                else
                    this->evento_recursoAbandonado("ouro");
                break;

            /*   - Invasao  */
            case 2:
                this->evento_invasao(fase);
                break;

            /*   - Alianca Diplomatica  */
            case 3:
                this->evento_aliancaDiplomatica();
                break;

            /*   - Sem Evento   */
            default:
                cout << "Nenhum evento aconteceu ao terminar a fase" << endl;
                break;
        }
    else {
        cout << "A executar evento pedido.. " << endl;
        if (nome.compare("recursoAbandonadoOuro") == 0)
            this->evento_recursoAbandonado("ouro");
        else if (nome.compare("recursoAbandonadoProduto") == 0)
            this->evento_recursoAbandonado("produto");
        else if (nome.compare("invasao") == 0)
            this->evento_invasao(fase);
        else if (nome.compare("aliancaDiplomatica") == 0) 
            this->evento_aliancaDiplomatica();
        else {
            cout << "\tErro no evento pedido, a executar um aleatorio!" << endl;
            switch (random) {
                case 1:
                    if (fase < 6)
                        this->evento_recursoAbandonado("produto");
                    else
                        this->evento_recursoAbandonado("ouro");
                    break;
                case 2:
                    this->evento_invasao(fase);
                    break;
                case 3:
                    this->evento_aliancaDiplomatica();
                    break;
                default:
                    cout << "Nenhum evento aconteceu ao terminar a fase" << endl;
                    break;
            }
        }
    }
}

void Imperio::evento_recursoAbandonado(string recurso) {
    if (recurso.compare("produto") == 0) {
        cout << "Recurso encontrado! ";
        cout << "Os batedores recuperaram 1 produto.";
        if (this->armazem < this->capacidade_armazem) {
            cout << endl << ">> +1 produto adicionado ao armazem!" << endl;
            this->armazem += 1;
        } else {
            cout << endl << "Armazem cheio! Produto desperdicado..." << endl;
        }
    } else if (recurso.compare("ouro") == 0) {
        cout << "Recurso encontrado! ";
        cout << "Os batedores recuperaram +1 ouro.";
        if (this->cofre < this->capacidade_cofre) {
            cout << endl << ">> +1 ouro adicionado ao armazem!" << endl;
            this->cofre += 1;
        } else {
            cout << endl << "Armazem cheio! Produto desperdicado..." << endl;
        }
    } else {
        cout << "[Erro] Nao existe evento com o recurso pedido" << endl;
    }
}

void Imperio::evento_invasao(int fase) {
    int posTerritorio = this->territorios_imperio.size() - 1;
    int forcaInvasao = 0;
    if (fase < 6)
        forcaInvasao = 2 + (rand() % 6 + 1);
    else
        forcaInvasao = 3 + (rand() % 6 + 1);
    
    int resistenciaTerritorio = this->territorios_imperio[posTerritorio].get_resistencia();
    cout << "Um imperio tentou invadir o territorio '" << this->territorios_imperio[posTerritorio].get_nome() << "'!" << endl;
    if (forcaInvasao > resistenciaTerritorio) {
        this->removeTerritorio(this->territorios_imperio[posTerritorio].get_nome());
    } else {
        cout << ">> Invasao sem sucesso.. ";
        cout << "[Invasores = " << forcaInvasao << "]";
        cout << "[Resistencia = " << resistenciaTerritorio << "]" << endl;
    }
}

void Imperio::evento_aliancaDiplomatica() {
    cout << "Foi assinada uma alianca com um imperio vizinho." << endl;
    if (this->forca_militar < this->capacidade_militar) {
        cout << "<< +1 forca militar!" << endl;
        this->forca_militar += 1;
    } else {
        cout << "Capacidade militar lotada. Alianca feita mas sem beneficios recebidos." << endl;
    }
}

void Imperio::produzMateriais() {
    // produz materiais de territorios para imperio
    int total_materiais = 0;
    int total_ouro = 0;
    // percorrer territorios
    for (size_t i=0; i<territorios_imperio.size(); i++) {
        total_materiais += territorios_imperio[i].get_criaProduto();
        total_ouro += territorios_imperio[i].get_criaOuro();
    }
    // adicionar ao imperio
    if (this->trocaOuro == true) {
        int dif = this->capacidade_cofre - total_ouro;
        while (dif - 2 >= 0) {
            this->adiciona_produtos(1);
            dif -= 2;
        }
        this->cofre = this->capacidade_cofre;
    } else {
        this->adiciona_ouro(total_ouro);
    }
    if (this->trocaOuro == true) {
        int dif = this->capacidade_armazem - total_materiais;
        while (dif - 2 >= 0) {
            this->adiciona_ouro(1);
            dif -= 2;
        }
        this->armazem = this->capacidade_armazem;
    } else {
        this->adiciona_produtos(total_materiais);
    }
}

string Imperio::getAsString() const {
    ostringstream os;
    os << ">> Territorios do Imperio" << endl;
    os << "\t";
    for (auto t : territorios_imperio)
        os << t.get_nome() << "  ";
    os << endl << endl << ">> Detalhes Imperio" << endl;
    // Ignorar Tecnologias
    os << "\tArmazem\t > " << armazem << " produtos de " << capacidade_armazem << " total"<< endl;
    os << "\tCofre\t > " << cofre << " ouro de " << capacidade_cofre << " total"<< endl;
    os << "\tMilitar\t > " << forca_militar << " militares de " << capacidade_militar << " total"<< endl;
    return os.str();
}

int Imperio::get_forcaMilitar() const { 
    return forca_militar; 
}

int Imperio::get_capacidadeForcaMilitar() const { 
    return capacidade_militar; 
}

int Imperio::get_tamanho() const {
     return this->territorios_imperio.size();
}

int Imperio::get_pontosConquista() const { 
    return pontosConquista; 
}

void Imperio::adiciona_pontosConquista() { 
    this->pontosConquista += 1; 
}

bool Imperio::imperioPerdido() const { 
    return this->perdido; 
}

void Imperio::adiciona_ouro(int maisOuro) {
    this->cofre += maisOuro;
    if (this->cofre > this->capacidade_cofre)
        this->cofre = this->capacidade_cofre;
}

void Imperio::adiciona_produtos(int maisProdutos) {
    this->armazem += maisProdutos;
    if (this->armazem > this->capacidade_armazem)
        this->armazem = this->capacidade_armazem;
}

void Imperio::adiciona_militar(int maisMilitar) {
    this->armazem += maisMilitar;
    if (this->armazem > this->capacidade_armazem)
        this->armazem = this->capacidade_armazem;
}

bool Imperio::aumenta_militar() {
    if (this->armazem >= 1 && this->cofre >= 1) {
        this->armazem -= 1;
        this->cofre -= 1;
        this->adiciona_militar(1);
        return true;
    } else {
        cout << "Nao foi possivel adquirir forca militar! (veja o cofre e armazem)" << endl;
        return false;
    }
}

bool Imperio::aumenta_produtos() {
    if (this->cofre >= 2) {
        this->cofre -= 2;
        this->adiciona_produtos(1);
        return true;
    } else {
        cout << "Troca de ouro por produtos impossivel por falta de ouro." << endl;
        return false;
    }
}

bool Imperio::aumenta_ouro() {
    if (this->armazem >= 2) {
        this->armazem -= 2;
        this->adiciona_ouro(1);
        return true;
    } else {
        cout << "Troca de produto por ouro impossivel por falta de produto." << endl;
        return false;
    }
}

void Imperio::mostra_tecnologias() const { 
    this->tecnologias.mostra_tecnologias(); 
}

int Imperio::get_nTecnologias() const { 
    return this->tecnologias.get_nTecnologias(); 
}

bool Imperio::adiciona_tecnologia(string nome) {
    if (nome.compare("dronesMilitares") == 0 && 
        this->cofre >= 3) {
        this->tecnologias.adiciona_tecnologia(nome);
        this->capacidade_militar = 5;
        this->cofre -= 3;
        return true;
    } else if (nome.compare("misseisTeleguiados") == 0 && 
        this->cofre >= 4) {
        this->tecnologias.adiciona_tecnologia(nome);
        this->conquistaQualquer = true;
        this->cofre -= 4;
        return true;
    } else if (nome.compare("defesasTerritoriais") == 0 && 
        this->cofre >= 4) {
        this->tecnologias.adiciona_tecnologia(nome);
        this->forca_militar += 1;
        this->cofre -= 4;
        return true;
    } else if (nome.compare("bolsaDeValores") == 0 && 
        this->cofre >= 2) {
        this->tecnologias.adiciona_tecnologia(nome);
        this->trocaOuro = true;
        this->cofre -= 2;
        return true;
    } else if (nome.compare("bancoCentral") == 0 && 
        this->cofre >= 2) {
        this->tecnologias.adiciona_tecnologia(nome);
        if (this->capacidade_armazem < 4)
            this->capacidade_armazem += 2;
        else this->capacidade_armazem = 5;
        if (this->capacidade_cofre < 4)
            this->capacidade_cofre += 2;
        else this->capacidade_cofre = 5;
        this->cofre -= 2;
        return true;
    } else 
        cout << "Erro ao adicionar tecnologia (falta de fundos)" << endl;
    return true;
}

void Imperio::set_forcaMilitar(int novaForca) { 
    forca_militar = novaForca; 
}

void Imperio::set_capacidadeForcaMilitar(int novaCapacidade) { 
    capacidade_militar = novaCapacidade; 
}

void Imperio::addTerritorio(Territorio &terr) { 
    territorios_imperio.push_back(terr); 
}

void Imperio::removeTerritorio(string nome) {
    int posTerritorio = -1;
    for (size_t i=0; i < this->territorios_imperio.size(); i++) {
        if (this->territorios_imperio[i].nome == nome) {
            posTerritorio = i;
            break;
        }
    }
    if (posTerritorio == -1) {
        cout << "[Erro] Nenhum territorio com o nome pedido!" << endl;
        return;
    } else {
        if (posTerritorio == 0) {
            this->perdido = true;
            cout << ">> Territorio Inicial perdido!" << endl;
        } else {
            cout << ">> Territorio '" << this->territorios_imperio[posTerritorio].nome << "' removido do Imperio!" << endl;
            if (posTerritorio > 0) posTerritorio -= 1;
            this->territorios_imperio.erase(this->territorios_imperio.begin() + posTerritorio);
        }
    }
}