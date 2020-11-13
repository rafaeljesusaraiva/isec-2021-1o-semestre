#include <sstream>
#include "Ponto.h"

using namespace std;

Ponto &Ponto::operator ++() {
    // incrementar x e y
    ++x;
    ++y; 
    return *this; // envia referência do objeto
}

string Ponto::getAsString() const {
    ostringstream os;
    os << "(" << x << ", " << y << ")";
    return os.str();
}

Ponto operator+(const Ponto &a, const Ponto &b) {
    Ponto soma(a.getX()+b.getX(), a.getY()+b.getY());
    return soma;
}

// Faz o operador == funcionar entre pontos
bool operator==(const Ponto &a, const Ponto &b) {
    return (a.getX() == b.getX() && a.getY() == b.getY());
}

// Faz o operador != funcionar entre pontos
bool operator!=(const Ponto &a, const Ponto &b) {
    return (a.getX() != b.getX() || a.getY() != b.getY());
}

// Faz com que o Ponto mostre o getAsString() quando está assim a seguir ao << (p.e. << ponto)
ostream &operator << (ostream &os, const Ponto &p) {
    os << p.getAsString();
    return os;
}