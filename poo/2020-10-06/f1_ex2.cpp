#include <iostream>
using namespace std;

// Tamanho máximo do input de string
#define MAX_STR_INPUT 255

int main () {
  char nome[MAX_STR_INPUT];
  int idade;

  // Obter input do nome
  cout << "Nome: ";
  cin.getline(nome, sizeof(nome));
  // Obter input da idade
  cout << "Idade: ";
  cin >> idade;
  // Inserir *newline*
  cout << endl;
  // Mostrar info
  cout << nome << " tem " << idade << " anos de idade." << endl;

  return 0;
}