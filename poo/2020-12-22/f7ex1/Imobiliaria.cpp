#include "Imobiliaria.h"
#include <sstream>

bool Imobiliaria::addImovel(Imovel *i) {
    if (i == nullptr)
        return false;
    imoveis.push_back(i);
    return true;
}

string Imobiliaria::getAsString() const {
    ostringstream os;
    os << "Nome: " << nome << endl;
    os << "Imoveis:" << endl;
    for (auto i : imoveis)
        os << "\t" << *i << endl;
    return os.str();
}

ostream &operator<< (ostream &os, const Imobiliaria &i) {
    os << i.getAsString();
    return os;
}