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
    cout << "Listagem da matriz:" << endl;
    for (int i=0; i<N; i++)
        cout << t.colunas[i] << " ";
    cout << endl;
}

// Alínea c)
int mostraElemento(Tabela t, int pos) {
    if (pos >= 0 && pos < N)
        return t.colunas[pos];
    else return 0;
}

// Alínea d)
void atualizaValor(Tabela &t, int pos, int novoValor) {
    if (pos >= 0 && pos < N) {
        t.colunas[pos] = novoValor;
    }
}

// Alínea e)
int &elementoAt(Tabela &t, int pos) {
    if (pos >= 0 && pos < N)
        return t.colunas[pos];
    else return t.colunas[0];
}

int main() {

    Tabela informacao;
    preenche_matriz(informacao, 5);
    lista_matriz(informacao);

    cout << mostraElemento(informacao, -1) << endl;
    cout << mostraElemento(informacao, 1) << endl;

    atualizaValor(informacao, 2, 3);
    lista_matriz(informacao);

    cout << "Muda elemento e mostra (alinea e):" << endl;
    elementoAt(informacao, 10) = 15;
    cout << elementoAt(informacao, 10) << endl;

    return 0;
}