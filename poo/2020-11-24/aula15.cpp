#include <iostream>
#include "Clube.h"

int main() {
    Pessoa p0("Joao", 10), p1("Maria", 20), p2("Jose", 30);
    Clube filatelia(5), pesca(2);

    filatelia.setMembroDoClube(&p0);
    filatelia.setMembroDoClube(&p1);

    pesca.setMembroDoClube(&p1);
    pesca.setMembroDoClube(&p2);

    cout << "Filatelia: " << filatelia.getAsString() << endl;
    cout << "Pesca: " << pesca.getAsString() << endl;

    Clube c3 = pesca;
    cout << "C3: " << c3.getAsString() << endl;

    Clube c4(filatelia);
    cout << "C4: " << c4.getAsString() << endl;
}