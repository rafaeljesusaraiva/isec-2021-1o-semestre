#include <iostream>
#include <string>

using namespace std;

// Função que receba uma string e um caracter e "devolva" quantas vezes o caracter aparece na string e o indice da primeira ocorrencia"
int deteta(string input, char caracter) {
    int indice = -1, ocorrencias = 0;
    
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == caracter) {
            if (indice == -1) indice = i;
            ocorrencias++;
        }
    }

    if (ocorrencias == 0) {
        cout << "Nao foi detetado o caracter pedido!" << endl;
    } else {
        cout << "Detetou primeiro " << caracter << " no indice " << indice << " da string." << endl;
    }
    

    return ocorrencias;
}

int main() {
    
    string s = "ABCDA";
    //cout << s.size() << endl;

    cout << deteta(s, 'A') << endl;
    cout << deteta(s, 'x') << endl;


    return 0;
}