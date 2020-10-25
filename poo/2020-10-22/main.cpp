#include <iostream>
#include <string>
#include "msg.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

MSG &teste() { // nao fazer retorno porque o objeto é destruido à saida
    MSG aux('y');

    string s;
    getline(cin, s);

    return aux;
}

int main() {
    MSG a('a');
    MSG b;

    MSG &c = b;

    // MSG d = b;
    // a = b;
    // MSG m[2] {'c', 'd'};
    teste();

    string s;
    getline(cin, s);

    // cout << b.getAsString() << endl;    

    return 0;
}