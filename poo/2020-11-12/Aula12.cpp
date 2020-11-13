#include <iostream>
#include "Ponto.h"

int main () {
    Ponto a(1, 2), b(2, 3);
    
    // cout << "a: " << a << endl;
    // Ponto x = ++a;
    // cout << "x (++a): " << x << endl;
    // cout << "a (depois de incrementado): " << a << endl;

    // if (a == b)
    //     cout << "A" << a << " e B" << b << " sao iguais\n";
    // else
    //     cout << "A" << a << " e B" << b << " sao diferentes\n";
    // Ponto z(1, 2);
    // if (a == z)
    //     cout << "A" << a << " e Z" << z << " sao iguais\n";
    // else
    //     cout << "A" << a << " e Z" << z << " sao diferentes\n";

    Ponto c = a + b;
    cout << "Ponto A: " << a << endl;
    cout << "Ponto B: " << b << endl;
    cout << "Ponto C (a+b): " << c << endl;
    Ponto e = b + 2;
    Ponto f = 4 + b;
    cout << "Ponto E (b+2): " << e << endl;
    cout << "Ponto F (4+b): " << f << endl;

    return 0;
}