#include <iostream>
#include <string>
using namespace std;

// APAGAR SUB-STRING DE STRING
void ex1() {
    string t = "Banana Republic";
    string s = "nana";
    string::size_type i = t.find(s);
    if (i != string::npos) t.erase(i, s.length());
}

// INSERIR STRING @ pos
str.insert(pos,str2);


// OVERLOADING CLASS CASTING OUTPUT
class ex1 {
    int data;
public:
    operator int() const { return data; }
};
void ex_ex1(){ 
    ex1 a;
    cout << (int) a; 
}

// CONTA PALAVRAS NUMA STRING
int tot_palavras(string strString){
   int nEspacos = 0;
    unsigned int i = 0;

    while(isspace(strString.at(i))) i++;

    for(; i < strString.length(); i++)
        if(isspace(strString.at(i))) {
            nEspacos++;
            while(isspace(strString.at(i++)))
                if(strString.at(i) == '\0')
                    nEspacos--;
        }

    return nEspacos + 1;
}

// ENCONTRA PALAVRA IN STRING
void ex3() {
    string s1, s2;
    if (s1.find(s2) != string::npos)
    cout << "found!" << '\n';
}


// ADD STRING TO STRING
void ex4() {
    string a, b;
    a.append(b)
    a += b;
}


