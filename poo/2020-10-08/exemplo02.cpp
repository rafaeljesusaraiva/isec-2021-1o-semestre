#include <iostream>

using namespace std;

int main() {
    cout << "Introduza um número " << endl;
    cout << "leitura como inteiro " << endl;
    int n;
    cin >> n;
    if (cin.good()) // verifica se leitura correu bem
        cout << "valor de n e " << n << endl;
    else {
        cout << "Introduza um string " << endl;
        // Fazer limpeza da flag de erro em leituras anteriores
        cin.clear(); 
        string s;
        cin >> s;
        cout << "valor de s e " << s << endl;
    }
}