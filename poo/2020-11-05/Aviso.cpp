#include "Aviso.h"

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

Aviso::Aviso(string s, Prego *pre) : msg(s), p(pre) {
    cout << "[DEBUG] Construindo => " << getAsString() << endl;
}

Aviso::~Aviso() {
    cout << "[DEBUG] Destruindo => " << getAsString() << endl;
}

string Aviso::getAsString() const {
    ostringstream os;
    os << "Aviso: " << msg << " em " << this->p->getAsString();
    return os.str();
}

string Aviso::getLocal() const {
    ostringstream os;
    os << "(" << this->p->getX() << ", " << this->p->getY() << ")";
    return os.str();
}