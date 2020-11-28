#include "Pessoa.h"

ostream &operator << (ostream &os, const Pessoa &p) {
    os << p.getNome() << " " << p.getIdade();
    return os;
}