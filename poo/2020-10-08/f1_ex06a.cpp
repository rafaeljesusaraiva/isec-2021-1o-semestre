#include <iostream>
#include <string>

using namespace std;

void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int a = 5, b = 10;
    cout << "a = " << a << "\nb = " << b << endl;
    troca(&a, &b);
    cout << "\nTroca\na = " << a << "\nb = " << b << endl;
}