#include "Interacao.h"

using namespace std;

int main() {

    cout << "JOGO POO" << endl;

    Interacao Jogador;

    do {
        Jogador.setComando();
    } while (Jogador.getFim() == false);

    return 0;
}