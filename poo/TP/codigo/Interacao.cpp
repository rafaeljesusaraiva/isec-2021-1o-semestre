#include "Interacao.h"
#include "Mundo.h"

void Interacao::setComando() {
    cout << "\n\tCOMANDO > ";
    cin >> comando;
    processComando();
}

void Interacao::processComando() {
    if (comando.compare("cria") == 0) {
        setMundo();
    } else if (comando.compare("carrega") == 0) {
        string nomeFich;
        cout << "Nome ficheiro: ";
        cin >> nomeFich;
        setMundo(nomeFich);
    } else if (comando.compare("sair") == 0) {
        fim = true;
    } else {
        cout << "Comando Errado" << endl;
    }
}

bool Interacao::setMundo(string fichName) {
    ifstream fich_obj;
    Mundo objeto;

    if (fich_obj.is_open()) {


        mundo = Mundo();
    }

    return false;
}

bool Interacao::setMundo() {
    
    return false;
}