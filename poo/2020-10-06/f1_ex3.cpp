#include <iostream>
using namespace std;

int main () {
  string nome;
  int idade;

  // Obter input do nome
  cout << "Nome: ";
  getline(cin, nome);
  // Obter input da idade
  cout << "Idade: ";
  cin >> idade;
  // Inserir *newline*
  cout << endl;
  // Mostrar info
  cout << nome << " tem " << idade << " anos de idade." << endl;

  return 0;
}