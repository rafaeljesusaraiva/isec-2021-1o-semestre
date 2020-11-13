#include <iostream>
#include <vector>
#include "ponto.h"
#include "retangulo.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    Ponto p1(1, 2);
    cout << "p1: " << p1.getAsString() << "\n";
    Retangulo a(p1, 5, 10);
    cout << "a: " << a.getAsString() << "\n";
    cout << "area: " << a.area() << endl;

/*    vector<string> c{ "como vai?", "tudo bem?" };
    c.insert(c.cbegin(), "ola!");
    for (auto r : c)
        cout << r << "\n";

 /*   vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int>::const_iterator it;
    for (it = v.cbegin(); it != v.cend() && *it != 5; ++it)
        ;
    v.erase(it, v.cend());
    for (auto e : v)
        cout << e << "  ";
    cout << endl;

    /*    auto  it = v.cbegin();
    while (it != v.cend()) {
        if (*it % 2)
            it = v.erase(it);
        else
            ++it;
    }
    for( it = v.cbegin(); it != v.cend(); ++it)
        cout << *it << "  ";
    cout << endl;

 /*   vector<int> v{ 1, 2, 3, 4 };
    vector<int>::iterator  b = v.begin();
    while (b != v.end()) {
        (*b) = (*b) * 2;
        b++;
    }
    vector<int>::const_iterator c = v.cbegin();
    while (c != v.cend()) {
        cout << *c << "  ";
        ++c;
    }
    cout << endl;

/*
/*  Retangulo b(p1, 50, 100);
    cout << "b: " << b.getAsString() << "\n";

    Ponto p2(4, 5);
    a.setCanto(p2);
    cout << "a: " << a.getAsString() << "\n";
    cout << "b: " << b.getAsString() << "\n";
    */
    /*
    Ponto mat[3];// = { {1, 3}, {2, 4}, {5, 7} };
    for( auto p : mat)
        cout << p.getAsString() << "\n";

    /*
    const Ponto c(5, 6);
    cout << "c: " << c.getAsString() << "\n";
    cout << "c.x: " << c.getX() << "\n";
    //c.setX(4);
    */
    /*Ponto a(1, 2);
    cout << "a: " << a.getAsString() << "\n";
    Ponto b(3, 4);
    cout << "b: " << b.getAsString() << "\n";
    cout << a.distancia(b) << endl;*/
}
