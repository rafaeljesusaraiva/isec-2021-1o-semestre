#include <iostream>
#include <string>

using namespace std;

void separa_string(string input, string match = "Silva") {
    size_t ultima = 0; 
    size_t prox = 0; 
    string palavra;
    bool conhece = false;

    // Loop para percorrer string (input)
    // prox => guarda a posição do espaço após a posição em última
    // ultima => guarda a posição do início da palavra a imprimir
    // npos => Comparador para impedir que prox contenha lixo e imprima non-stop
    while ((prox = input.find(" ", ultima)) != string::npos) {
        // Guardar e imprimir palavra retirada da string
        palavra = input.substr(ultima, prox-ultima);
        cout << palavra << endl;
        // Confirma se a palavra atual é igual à procurada (match)
        if (palavra.compare(match) == 0)
            conhece = true;
        // Incrementa última posição
        ultima = prox + 1; 
    } 
    // Obter última palavra delimitando a string pela posição do ultima
    cout << input.substr(ultima) << endl;

    if (conhece)
        cout << "A string inserida contém a palavra '" << match << "'." << endl;
}

int main() {
    string nomeUtilizador;

    cout << "Nome do Utilizador: ";
    getline(cin, nomeUtilizador);

    separa_string(nomeUtilizador);
}