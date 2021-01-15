#include "Piranha.h"

ostream &operator<< (ostream &os, const Piranha &p) {
    os << p.getAsString() << " || Comprimento: " << p.getComprimento();
    return os;
}