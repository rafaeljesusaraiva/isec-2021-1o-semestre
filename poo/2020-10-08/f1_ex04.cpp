#include <iostream>
#include <string>

using namespace std;

// Function Overloading
//  > Várias funções com o mesmo nome, o programa identifica-as de acordo com os argumentos dados à chamada

void imprime(string output_string) {
    cout << output_string << endl;
}

void imprime(string output_string, int output_int) {
    cout << output_string << output_int << endl;
}

void imprime(int output_int, string output_string) {
    cout << output_int << output_string << endl;
}

int main() {
    imprime("ola");
    imprime("a idade é: ", 25);
    imprime(100, " euros");

    return 0;
}