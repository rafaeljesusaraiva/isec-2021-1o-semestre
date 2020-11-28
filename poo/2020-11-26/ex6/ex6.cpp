#include <iostream>
#include "Agenda.h"

int main() {

    Agenda a;
    a.adicionaContacto("Pedro", 123);
    a.adicionaContacto("Maria", 666);
    a.adicionaContacto("Maria Jose", 666);
    a.adicionaContacto("Maria Filomena", 666);

    cout << a << "\n";

    a.gravaAgenda("agenda.txt");

    return 0;
}