#include <sstream>
#include "ParOrdenado.h"

using namespace std;

ostream &operator << (ostream &os, const ParOrdenado &p) {
    os << "<" << p.getA() << ", " << p.getB() << ">";
    return os;
}