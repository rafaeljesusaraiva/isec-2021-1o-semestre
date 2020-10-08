#include <iostream>
#include <string>
using namespace std;
void exemplo1() {
    cout << "introduza um numero " << endl;
    cout << "leitura como inteiro" << endl;
    int n;
    cin >> n;
    cout << "valor de n e " << n << endl;

    cout << "leitura como string" << endl;
    string s;
    cin >> s;
    cout << "valor de s e " << s << endl;
}

void exemplo2() {
    cout << "introduza um numero " << endl;
    cout << "leitura como inteiro" << endl;
    int n;
    cin >> n;
    cout << "valor de n e " << n << endl;

    cout << "cin.clear() + leitura como string" << endl;
    cin.clear(); //limpar a flag de erro
    string s;
    cin >> s;
    cout << "valor de s e " << s << endl;
}
void exemplo3() {
    cout << "introduza um numero " << endl;
    cout << "leitura como inteiro" << endl;
    int n;
    cin >> n;
    if (cin.good()) //verificar se leitura correu bem
        cout << "valor de n e " << n << endl;
    else {
        cout << "cin.clear() + leitura como string" << endl;
        cin.clear(); //limpar a flag de erro
        string s;
        cin >> s;
        cout << "valor de s e " << s << endl;
    }
}
void exemplo4() {
    cout << "introduza um numero inteiro" << endl;
    int n;
    while(!(cin >> n)){
        cin.clear(); //limpar a flag de erro
        cin.ignore(1024, '\n');
        cout << "introduza um numero inteiro" << endl;
    }
    cout << "valor de n e " << n << endl;
}
void exemplo5() {
    cout << "Idade " << endl;
    int idade;
    cin >> idade;

    cout << "Nome: " << endl;
    string nome;
    getline(cin, nome);

    cout << nome << " tem " << idade << " anos." << endl;
}
void exemplo6() {
    cout << "Idade " << endl;
    int idade;
    cin >> idade;

    cout << "Nome: " << endl;
    cin.ignore(1, '\n');
    string nome;
    getline(cin, nome);

    cout << nome << " tem " << idade << " anos." << endl;
}
void imprime(string texto) {
    cout << texto << endl;
}
void imprime(string texto, int idade) {
    cout << texto << " " << idade << endl;
}
void imprime(int valor, string texto) {
    cout << valor << " " << texto << endl;
}
string exemplo7(string s, int n=1, char c='s') {
    for (int i = 0; i < n; i++)
        s += c;
    return s;
}
/*int soma() {
    return 0;
}
int soma(int n) {
    return n;
}
int soma(int n, int x) {
    return n + x;
}
int soma(int n, int x, int y) {
    return n + x + y;
}*/
int soma(int n1 = 0, int n2 = 0, int n3 = 0) {
    return n1 + n2 + n3;
}
void exemplo9() {
    int i = 1024;
    cout << i << endl;

    int &refI = i;
    refI = 10;
    cout << i << endl;

    int &ref2 = refI;
    ref2 = 5;
    cout << i << endl;
}

void reset(int &i) {
    i = 0;
}

void troca(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void troca(int &a, int &b) {
    int temp;

    temp = a;
    a = b;
    b = temp;
}
//Função que receba uma string e um carater e "devolva" quantas vezes o carater aparece na string e
//o índice da primeira ocorrencia
int contaChar(const string &s, char c, int &pos) {
    pos = -1;
    int contador = 0;
    int primeira = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            if (primeira == 0) {
                pos = i;
                primeira = 1;
            }
            contador++;
        }
    }
    return contador;
}

int main()
{
    string s = " Bom dia amigo! ";
    int conta, indice;
    conta = contaChar(s, 'u', indice);
    if (conta == 0)
        cout << " A letra nao aparece" << endl;
    else
        cout << "posicao: " << indice << " aparece " << conta << " vezes." << endl;
    //string s = "ABCD";
    //cout << s.size();

 /*   int a = 5, b = 10;
    troca(&a, &b);
    cout << "\na = " << a << "\nb = " << b << endl;

    troca(a, b);
    cout << "\na = " << a << "\nb = " << b<<endl;
    */
    /*    int var = 25;
    cout << var << endl;
    reset(var);
    cout << var << endl;
*/
    //exemplo9();
    //cout << "\n" << soma() << " " << soma(1) << endl;
    //cout << soma(1, 2) << " " << soma(1, 2, 3)<< endl;

 /*   string novaS = exemplo7("teste", 3, 'X');
    cout << novaS << endl;
    cout << "plural de carro e' " << exemplo7("carro") << endl;
    cout << exemplo7("cantiga", 5);
 */
 /*   imprime("ola");
    imprime("a idade é: ", 25);
    imprime(100, "euros");
  */
  //exemplo6();
}
