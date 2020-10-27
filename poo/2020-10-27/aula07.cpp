#include <iostream>
#include <vector>
#include <initializer_list>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::initializer_list;

void mensagem_erro(initializer_list<string> i1) {
    for (auto i : i1)
        cout << i << "  ";
    cout << endl;
}

int main() {

    // string esperado = "esperado: XPTO", obtido = "obtido XXXXX";
    string esperado = "esperado: XPTO", obtido = "esperado: XPTO";
    if (esperado != obtido)
        mensagem_erro({
            "funcao X:", esperado, obtido
        });
    else
        mensagem_erro({
            "funcao X:", "OK"
        });

    // initializer_list<string> ls;
    // initializer_list<int> li;

    // vector<int> ivec;
    // for (int i=0; i<100; i++) ivec.push_back(i);
    // // for (auto i: ivec) cout << i << " ";

    // vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // for (auto &i : v)
    //     i *= i;

    // for (auto i : v) // igual a: for (int i=0; i<v.size(); i++)
    //     cout << i << " ";
    // cout << endl;

    // vector<int> ivec2(ivec); // vetor por cópia
    // vector<int> ivec3 = ivec; // vetor por inicialização

    // vector<string> svec;
    // vector<string> artigos = {"o", "a", "os", "as"};

    // vector<string> svec4(5, "ola"); // guardada string "ola" 5x
    // vector<int> ivec4(10, -1); // guardado valor -1 10x

}