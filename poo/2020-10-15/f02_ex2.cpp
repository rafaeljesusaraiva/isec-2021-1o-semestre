#include <iostream>
#include <string>

using namespace std;

class Tabela {
    // private:     // Não é preciso porque até public, tudo é privado
        static int const N = 15;
        int matriz[N];

        // Função privada (só chamada "dentro" da classe)
        void preenche_matriz(int m[], int digito) {
            for (int i=0; i<N; i++)
                m[i] = digito;
        }

    public: // Tudo abaixo é acessível fora da classe (main, etc.)
        // Construtor da Classe
        // - Executa na chamada inicial da classe
        // - Pode receber valores iniciais
        Tabela(int pre = 0) {
            preenche_matriz(matriz, pre);
        }

        // Declaração interna dos métodos (funções)
        void mostraMatriz() const;
        int getTamanho() const { return N; }

        int &elementoEm(int pos) {
            if (pos >=0 && pos < N)
                return matriz[pos];
            else
                return matriz[0];
        }
};

// Também é possível escrever os métodos fora da classe
// Iniciliza-se com [Classe]::[Função]
void Tabela::mostraMatriz() const {
    for (int i=0; i<N; i++)
        cout << matriz[i] << " ";
    cout << endl;
}

int main() {

    Tabela t;

    t.mostraMatriz();

    t.elementoEm(5) = 1;
    cout << t.elementoEm(5) << endl;

    t.mostraMatriz();

    return 0;
}