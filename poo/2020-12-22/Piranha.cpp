#include "Piranha.h"
#include <ostream>

Piranha &Piranha::operator= (const Piranha &p) {
    Peixe::operator=(p);
    comprimento = p.comprimento;
    return *this;
}

ostream &operator<< (ostream &os, const Piranha &p) {
    os << p.getAsString();
    return os;
}

string Piranha::getAsString() const {
    ostringstream os;
    os << this->Peixe::getAsString() << " || Comprimento: " << comprimento;
    return os.str();
}