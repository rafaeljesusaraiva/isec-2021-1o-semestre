#include <iostream>
#include "Fracao.h"
using namespace std;

void func (int n) {
    cout << n << endl;
}

int main() {
    Fracao a(1, 2), b(3);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    func(a);
    cout << a * Fracao(4) << endl;
    cout << static_cast <int> (a) * 4 << endl;
    func(static_cast <int> (a));
    
    // ++a;
    // cout << "a (incrementada 1 unidade): " << a << endl;

    // const Fracao c(3, 4);
    // cout << "c: " << c << endl;
    // Fracao mult = a*c*b;
    // cout << "mult (=a*c): " << mult << endl;

    // a.setNumerador(5);
    // cout << "a (alterado): " << a.getNumerador() << "/" << a.getDenominador() << endl;

    return 0;
}