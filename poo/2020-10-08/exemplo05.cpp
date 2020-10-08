#include <iostream>
#include <string>

using namespace std;

// Concatenação de strings
//  > Acrescenta "n" caracteres "c" à string
//  > Caso não se dê um inteiro, usa '1' por defeito
//  > Caso não se dê um caracter, usa 's' por defeito
string acrescenta(string s, int n = 1, char c = 's') {
    for (int i = 0; i < n; i++)
        s += c;
    return s;
}

int main() {
    string novaString = acrescenta("teste", 3, 'X');
}