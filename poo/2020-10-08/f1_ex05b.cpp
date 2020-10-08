#include <iostream>
#include <string>

using namespace std;

int soma(int prim = 0, int seg = 0, int terc = 0) {
    return (prim + seg + terc);
}

int main() {
    cout << "\n" << soma() << soma(1);
    cout << soma(1,2) << soma(1,2,3);
}