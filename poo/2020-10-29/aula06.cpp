#include <iostream>
#include "retangulo.h"

using namespace std;

int main() {
    /*
    Ponto a(1, 2);
    cout << "a: " << a.getAsString() << endl;
    Ponto b(3, 4);
    cout << "b: " << b.getAsString() << endl;

    const Ponto c(5,6);
    cout << "Cx: " << c.getX() << endl;

    Ponto nulos[3];
    for (auto p: nulos)
        cout << p.getAsString() << endl;
    Ponto mat[3] = {{1, 3}, {2, 4}, {5, 7}};
    for (auto p: mat)
        cout << p.getAsString() << endl;
    */
    Ponto p1(1, 2);
    Retangulo a(p1, 1, 2), b(p1, 50, 100);
    cout << "p1: " << p1.getAsString() << endl;
    cout << "a: " << a.getAsString() << endl;
    cout << "b: " << b.getAsString() << endl;
    Ponto p2(4, 5);
    a.setCanto(p2);
    cout << "a: " << a.getAsString() << endl;
    cout << "area b: " << b.area() << endl;

    return 0;
}