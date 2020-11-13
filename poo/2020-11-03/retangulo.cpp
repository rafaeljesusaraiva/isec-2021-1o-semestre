#include "retangulo.h"
#include <sstream>

using namespace std;

Retangulo::Retangulo(const Ponto &p, double alt, double lar) : cse(p.getX()), altura(alt), largura(lar) {
    if (altura < 0) altura = -altura;
    if (largura < 0) largura = -largura;
    // cout << "[DEBUG] A construir " << getAsString() << endl;
}

Retangulo::~Retangulo() {
    // cout << "[DEBUG] A destruir " << getAsString() << endl;
}

string Retangulo::getAsString() const {
    ostringstream os;
    os << "Retangulo - ";
    os << "C.Sup.Esq.: " << cse.getAsString();
    os << "Altura: " << altura;
    os << " Largura: " << largura;
    return os.str();
}

double Retangulo::area() const { return altura * largura; }

void Retangulo::setCanto(const Ponto &p) { cse = p; }