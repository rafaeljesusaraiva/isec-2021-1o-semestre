#include "Peixe.h"
#include "Aquario.h"
double getRealUniform();

unsigned int Peixe::conta = 500;

Peixe::Peixe(string especie, string cor)
    :especie(especie), cor(cor), num_serie(conta++) {}

void Peixe::come(unsigned int c) {
    if (indigestao) {
        if (resta > 0)
            --resta;
        return;
    }
    peso += c;
    if (peso > 50) {
        if (getRealUniform() < 0.5) {
            Peixe *peixinho = new Peixe(especie+"D", cor);
            aquario->addPeixe(peixinho);
            peso = 40;
        } else {
            indigestao = true;
            peso /= 2;
        }
    }
}

bool Peixe::ligaAquario(Aquario *a) {
    if (aquario != nullptr || a == nullptr)
        return false;
    aquario = a;
    return true;
}

bool Peixe::desligaAquario(Aquario *a) {
    if (aquario != a)
        return false;
    aquario = nullptr;
    return true;
}

string Peixe::getAsString() const {
    ostringstream os;
    os << "N. Serie: " << num_serie << " || Especie: " << especie;
    os << " || Cor: " << cor << " || Peso: " << peso;
    return os.str();
}

ostream &operator<< (ostream &os, const Peixe &p) {
    os << p.getAsString();
    return os;
}