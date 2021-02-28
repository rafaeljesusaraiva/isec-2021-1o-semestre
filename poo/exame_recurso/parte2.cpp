#include <iostream>
#include <vector>
using namespace std;


class Sequencia {
private:
    int valor_inicial, quantos;
    string tipo;
    vector<int> numeros;
    // ...
public:
    Sequencia (int inic, int rep): valor_inicial(inic), quantos(rep) {}
    virtual void preenche() {
        for (int i=0; i<quantos; i++) {
            if (tipo.compare("geo") == 0) {}
            else {
                
            }
            numeros.push_back();
        }
    }
};

class Geometrica : public Sequencia {
public:
    Geometrica (int inic, int rep, int fator) {}
};

class Quadrado : public Sequencia {
public:
    Quadrado (int inic, int rep) {
        
    }
};

void main() {

}


// a)
class XYZ {
vector <BC*> ptrs;
public:
XYZ(const XYZ &p2) {
for (int i=0; i<(p2.ptrs).size(); i++)
ptrs.push_back(p2.ptrs[i]);
}

virtual XYZ& operator = (XYZ &p2) {
ptrs.clear();
for (int i=0; i<(p2.ptrs).size(); i++)
ptrs.push_back(p2.ptrs[i]);
}

BC& operator [] (int i) {
    return *ptrs[i];
}
};
// Os ponteiros foram copiados um a um quando o objeto desta classe é criado ou atribuido um outro objeto numa igualdade.
 
// b)
class BC {};

class XYZ {
vector <BC*> ptrs;
public:
XYZ(const XYZ &p2) {
ptrs = p2.ptrs;
}

virtual XYZ& operator= (XYZ &p2) {
ptrs.clear();
ptrs = p2.ptrs;
}

virtual XYZ& operator= (BC &b2) {
ptrs.clear();
ptrs.push_back(&b2);
}
};
// Neste caso copia-se o endereço do vetor diretamente para a classe, para se tornar agregação. E não se copia um a um.