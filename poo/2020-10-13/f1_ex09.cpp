#include <iostream>
#include <string>

using namespace std;

bool numerico (string input) {

    if (input.compare("fim") == 0)
        return true;

    string extenso[10] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez"};

    if (isdigit(input[0])) {
        int int_input = stoi(input);
        if (int_input > 0 && int_input < 11)
            cout << "O numero inserido escreve-se assim: " << extenso[int_input-1] << endl;
    } else {
        for (int i=0; i<10; i++) {
            if (extenso[i].compare(input) == 0)
                cout << "O numero escrito numericamente é assim: " << i+1 << endl;
        }
    }

    return false;
}

int main() {
    string input_utilizador;
    bool verif = false;

    do {
        cout << "Insira um numero entre 1 e 10: ";
        cin >> input_utilizador;
        verif = numerico(input_utilizador);
    } while (!verif);
}