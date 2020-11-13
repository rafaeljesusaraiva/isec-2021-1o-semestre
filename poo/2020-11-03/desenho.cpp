#include "desenho.h"
#include <sstream>

using namespace std;

string Desenho::getAsString() const {
    ostringstream os;
    os << "Desenho: " << this->nome;
    if (this->figuras.empty())
        os << ", em branco...";
    else {
        os << ", com: ";
        for (auto r: this->figuras)
            os << "\n  " << r.getAsString();
    }
    return os.str();
}

bool Desenho::addFigura(Retangulo &r) {
    this->figuras.push_back(r);
    return true;
}

void Desenho::removeAreaMaior(double a) {
    auto i = this->figuras.begin();
    while (i != this->figuras.end()) {
        if (i->area() > a)
            i = this->figuras.erase(i);
        else i++;
    }
}