#include <iostream>
#include <string>
#include <vector>
#include "ABC.h"

using namespace std;

void gastaMem() {
    ABC temp("Texto temporario que ocupa espaco");
}

void func(ABC x) {}
void func() {
    ABC a("aaa");
    ABC b("bbb");
    a = b;
}

int main() {

    ABC y("ola");
    // func(y);
    cout << y.getConteudo();
    cout << "o programa deve ter rebentado";
    func();
    cout << "o programa deve ter rebentado outra vez";


    return 0;
}