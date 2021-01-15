#include "Imovel.h"
#include <sstream>

int Imovel::conta = 1;

string Imovel::getAsString() const {
    ostringstream os;
    os << codigo << " || Area: " << area << " || Andar: " << andar << " || Preco: " << preco;
    return os.str();
}

ostream &operator<< (ostream &os, const Imovel &i) {
    os << i.getAsString();
    return os;
}