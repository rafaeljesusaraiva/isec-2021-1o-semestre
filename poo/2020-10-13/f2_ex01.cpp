#include <iostream>
#include <string>

using namespace std;

#define N 15

struct Tabela {
    int colunas[N];
};

// Alinea a)
void preenche_matriz(Tabela &t, int digito) {
    for (int i=0; i<N; i++)
        t.colunas[i] = digito;
}

// Alinea b)
void lista_matriz(Tabela t) {
    for (int i=0; i<N; i++)
        cout << t.colunas[i] << " ";
}

int main() {

    Tabela informacao;
    preenche_matriz(informacao, 5);
    lista_matriz(informacao);

    return 0;
}