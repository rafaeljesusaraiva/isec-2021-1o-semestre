// aula01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  
void f1e1a() {
    char nome[50];
    int idade;
    printf("Nome: ");
    scanf_s("%s", nome, 49);
    printf("idade: ");
    scanf_s("%d", &idade);

    printf("%s tem %d anos\n", nome, idade);
    double n = 3.7;
    printf("%d\n", n);
}

void exemplo2() {
    std::cout << "Introduza dois numeros" << std::endl; //apresenta frase
                                    //envia para saída standard e muda de linha
    int v1, v2; //declaração onde se usa
    std::cin >> v1 >> v2;      
    std::cout << "soma de " << v1 << " com " << v2 << " da " << v1 + v2 
              << std::endl;
}

//using std::cin;  //também podia ser assim
//using std::cout;
//using std::endl;
using namespace std; //para poder omitir o namespace dos objetos
void exemplo3() {
    cout << "Introduza dois numeros" << endl; 
    int v1, v2; //declaração onde se usa
    cin >> v1 >> v2;
    cout << "soma de " << v1 << " com " << v2 << " da " << v1 + v2 << endl;
}
void f1e2a() {
    cout << "nome: " << endl;
    char nome[50]; 
    cin >> nome;
    cout <<"idade: "<<endl;
    int idade;
    cin >> idade;

    cout << nome << " tem " << idade  << " anos." << endl;
}

//using std::string;
void exemplo4() {
    string s1; //string vazia
    cout << "s1:" << s1 << endl;
    string s2 = s1; //s2 é uma cópia de s1
    cout << "s2:" << s2 << endl;
    string s3 = "Bom dia"; //s3 é uma cópia da string literal
    cout << "s3:" << s3 << endl;
    string s4(10, 'c'); // s4 é cccccccccc
    cout << "s4:" << s4 << endl;
}
//using std::string;
void f1e3a() {
    cout << "nome: " << endl;
    string nome; //sequencia de carateres de tamanho variável
    cin >> nome;
    cout << "idade: " << endl;
    int idade;
    cin >> idade;

    cout << nome << " tem " << idade << " anos." << endl;
}

void exemplo5() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
    //if (s1.size() == s2.size())
        cout << "strings identicas"<<endl;
        //cout << "strings do mesmo tamanho" << endl;
    else
        if (s1 > s2)
        //if (s1.size() > s2.size())
            cout << s1 << " e' maior que " << s2 << endl;
        else
            cout << s1 << " e' menor que " << s2 << endl;
}

void exemplo6() {
    string frase = "bom dia, frase de exemplo!!!!";
    for (char letra: frase)
        cout << letra << endl;
}

void exemplo7() {
    string frase = "bom dia, frase de exemplo!!!!";
    for (auto letra : frase)
        cout << letra << endl;
}

void exemplo8() {
    cout << "Introduza uma palavra" << endl;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        s[i] = 'X';
    cout << s << endl;
}

#include <string>
void exemplo9() {
    cout << "nome: " << endl;
    string nome;
    getline(cin, nome); //lê até oa \n
    int idade;
    cout << "idade: " << endl;
    cin >> idade;

    cout << nome << " tem " << idade << " anos." << endl;
}

void exemplo10() {
    string s;
    cout << "Introduza uma palavra" << endl;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        s[i] = 'X';
    cout << s << endl;
}



int main()
{
    exemplo6();
    //exemplo5();
    //exemplo4();
    //f1e2a();
    //exemplo3();
    //f1e1a();
    //std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
