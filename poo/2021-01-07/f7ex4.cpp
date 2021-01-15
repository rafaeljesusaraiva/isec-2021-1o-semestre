#include <iostream>
#include "Apressado.h"
#include "Cliente.h"

int main() {

    Tarifario *t = new Apressado;
    Cliente c("Jose", 123123123, t);

    Cliente d(c);
    Cliente e("Maria", 23232, nullptr);
    e = c;

    // cout << "Antes de adicionar Treinos:\n    " << c << endl;
    // c.iniciaTreino(0);
    // c.iniciaTreino(10);
    // c.terminaTreino(30);
    // c.iniciaTreino(50);
    // c.terminaTreino(100);
    // cout << "Depois de adicionar Treinos:\n    " << c << endl;
    // cout << "Valor a pagar: " << c.paga() << endl;
    // cout << "Depois de pagar os treinos:\n    " << c << endl;
    return 1;
}