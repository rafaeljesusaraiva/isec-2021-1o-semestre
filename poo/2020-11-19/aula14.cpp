#include <iostream>
#include <string>
#include <vector>
#include "MSG.h"
#include "ABC.h"

using namespace std;

// void func(MSG* &a, MSG* &b) {
//     a = new MSG("msgA");
//     b = new MSG("msgB");
//     cout << "objetos criados";
// }

void gastaMem() {
    ABC temp("Texto temporario que ocupa espaco");
}

void func(ABC x) {}

void func() {
    ABC a("aaa");
    ABC b("bbb");
    // a = b;
}

int main() {

    ABC y("ola");
    // func(y);
    cout << y.getConteudo();
    cout << "o programa deve ter rebentado";
    func();
    cout << "o programa deve ter rebentado outra vez";

/*
    for (unsigned int i = 0; i < 100000000; i++)
        gastaMem();
    cout << "o programa deve ter terminado por falta de mem";
*/
/*
    MSG *am = new MSG[3];
    delete[] am;
*/
/*
    int *ai = new int[10];
    int *bi = new int[10]();
    int *ci = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 10; i++)
        ci[i] *= 2;

    for (int *p = ci; p < ci+10; p++)
        cout << "  " << *p;
    cout << endl;

    delete[] ai;
    ai = nullptr;
*/
/*
    MSG *a = nullptr, *b = nullptr;
    func(a, b);
    delete a;
    a = nullptr;
    delete b;
    b = nullptr;
    cout << "Objetos libertados" << endl;
*/
/*
    EXPLICAÇÃO MEM. DINÂMICA

    int i, *pi1 = &i, *pi2 = nullptr;
    double *pd = new double(33), *pd2 = pd;

    delete i; // não dá porque não é um ponteiro
    // delete pi1;
    if (pi2 != nullptr)
        delete pi2;
    delete pd;
    // pd = nullptr;


    // ponteiro int
    int *pi = new int(1024); 
    // ponteiro string
    string *ps = new string(5, '9'); 
    vector <int> *pv = new vector<int>{1, 2, 3, 4, 5, 6, 7};
    int *qi = new int();

    cout << *pi << " " << *ps << " " << *qi << " " << endl;
    
    apaga o ponteiro pi
    delete pi;
*/
    return 0;
}