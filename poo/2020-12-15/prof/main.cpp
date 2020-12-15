// Ficha6Ex1.cpp : 
#include <iostream>
#include <random>
#include <ctime>
#include "Peixe.h"
#include "Aquario.h"

using namespace std;

double getRealUniform() {
    static default_random_engine e(time(0));
    static uniform_real_distribution<double> d(0.0, 1.0);
    return d(e);
}

int main()
{
    Peixe *p1 = new Peixe("Nemo", "laranja");
    Peixe *p2 = new Peixe("Dory");
    Peixe *p3 = new Peixe("Bolhas", "amarelo");

    Aquario a;
    a.addPeixe(p1);
    a.addPeixe(p2);
    a.addPeixe(p3);
    cout << a << endl;
    
    a.alimentaPeixes(50);
    cout << a << endl;
    
    for (auto i = 0; i < 5; i++) {
        a.alimentaPeixes(5);
        cout << a << endl;
    }
    a.selfClean();
    cout << a << endl;

    /*p1->come(50);
    p2->come(50);
    p3->come(50);
    cout << a << endl;
    */

/*    for (int i = 0; i < 10; i++)
        cout << getRealUniform() << endl;
        */

/*    default_random_engine re;
    for (int i = 0; i < 10; i++)
        cout << re() << endl;
        */

        /*
    Peixe *p1 = new Peixe("Nemo", "laranja");
    Peixe *p2 = new Peixe("Dory");
    Peixe *p3 = new Peixe("Bolhas", "amarelo");

    Aquario a;
    a.addPeixe(p1);
    a.addPeixe(p2);
    a.addPeixe(p3);
    
    cout << a << endl;*/
}
