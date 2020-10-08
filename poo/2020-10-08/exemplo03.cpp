#include <iostream>

using namespace std;

int main() {
    cout << "Introduza um número inteiro" << endl;
    int n;
    cin >> n;
    while (!(cin >> n)) {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "Introduza um número inteiro" << endl;
    }
    cout << "valor de n e " << n << endl;
}