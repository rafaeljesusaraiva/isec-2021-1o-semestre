#include <iostream>
#include <vector>
#include "desenho.h"
#include "retangulo.h"
#include "ponto.h"

using namespace std;

int main() {

    Ponto p1(1, 2);
    cout << "p1: " << p1.getAsString() << endl;

    Retangulo r1(p1, 5, 10);
    cout << "r1: " << r1.getAsString() << endl;
    // cout << "area: " << r1.area() << endl;

    Desenho d("Primeiro");
    d.addFigura(r1);
    Ponto p2(5, 5);
    Retangulo r2(p2, 4, 4);
    d.addFigura(r2);
    cout << d.getAsString() << endl;
    d.removeAreaMaior(20);
    cout << d.getAsString() << endl;

    /*
        EXEMPLOS DE COMPREENSÃO
    */

    // vector<string> c{"como vai?", "tudo bem?"};
    // c.insert(c.begin(), "ola!");
    // for (auto r : c)
    //     cout << r << "\n";

    // vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // vector<int>::const_iterator it;
    // for (it=v.cbegin(); it!=v.cend() && *it!=5; ++it)
    //     ;
    // v.erase(it, v.cend()-1);
    // for (auto e : v)
    //     cout << e << " ";
    // cout << endl;
    
    // auto it = v.cbegin();
    // while (it != v.cend()) {
    //     if (*it % 2)
    //         it = v.erase(it);
    //     else
    //         ++it;
    // }
    // for (it = v.cbegin(); it != v.cend(); ++it)
    //     cout << *it << " ";

    return 0;
}