#ifndef ABC_H
#define ABC_H
#include <iostream>
#include <cstring>
using namespace std;

void copiaCaracteres(char *d, const char *o) {
    size_t tam = strlen(o);
    for (size_t i = 0; i < tam; i++)
        d[i] = o[i];
    d[tam] = o[tam];
}

class ABC {
    char *p;
public:
    ABC(const char *s) {
        p = new char[strlen(s) + 1];
        strcpy(p, s);
    }
    ABC(const ABC &o) {
        p = nullptr;
        *this = o;
    }
    ~ABC() {
        delete[] p;
    }
    const char *getConteudo() const { return p; }
    // ABC &operator = (const ABC &a) = delete;
    // ABC &operator = (const ABC &a) {
    //     char *copia = new char[strlen(a.p)+1];
    //     copiaCaracteres(copia, a.p);
    //     if (p != nullptr)
    //         delete p;
    //     p = copia;
    //     return *this;
    // }
    ABC &operator = (const ABC &a) {
        // faz o mesmo que o anterior
        if (this == &a)
            return *this;
        if (p != nullptr)
            delete p;
        p = new char[strlen(a.p)+1];
        copiaCaracteres(p, a.p);
        return *this;
    }
};

#endif // !ABC_H