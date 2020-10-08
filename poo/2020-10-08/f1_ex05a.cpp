#include <iostream>
#include <string>

using namespace std;

int soma() {
    return 0;
}

int soma(int prim) {
    return prim;
}

int soma(int prim, int seg) {
    return (prim + seg);
}

int soma(int prim, int seg, int terc) {
    return (prim + seg + terc);
}

int main() {
    cout << "\n" << soma() << soma(1);
    cout << soma(1,2) << soma(1,2,3);
}