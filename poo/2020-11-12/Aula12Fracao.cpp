#include <iostream>
#include "Fracao.h"
using namespace std;

int main() {
    Fracao a(1, 2);
    Fracao b(3);
    const Fracao c(3, 4);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    ++a;
    cout << "a (incrementada 1 unidade): " << a << endl;

    // Fracao mult = a*c*b;
    // cout << "mult (=a*c): " << mult << endl;

    // a.setNumerador(5);
    // cout << "a (alterado): " << a.getNumerador() << "/" << a.getDenominador() << endl;

    return 0;
}