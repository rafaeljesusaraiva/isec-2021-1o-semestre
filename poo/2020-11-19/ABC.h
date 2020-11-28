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
    ABC(ABC &o) = delete; // ignora inicialização assim
    ~ABC() {
        delete[] p;
    }
    const char *getConteudo() const { return p; }
    ABC &operator = (const ABC &a) = delete;
};

#endif // !ABC_H