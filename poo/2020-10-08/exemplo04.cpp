#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Idade " << endl;
    int idade;
    cin >> idade;

    cout << "Nome: " << endl;
    // Garantir que o getline consiga ler para o proximo input
    cin.ignore(1, '\n');
    string nome;
    getline(cin, nome);

    cout << nome << " tem " << idade << " anos." << endl;
}