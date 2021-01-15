#include "Peixe.h"
#include "Aquario.h"
double getRealUniform();

unsigned int Peixe::conta = 500;

bool Peixe::setPeso(int g) {
    if (peso <= 0)
        return false;
    peso = g;
    return true;
}

Peixe::Peixe(string especie, string cor)
    :especie(especie), cor(cor), num_serie(conta++) {}

Peixe::Peixe(const Peixe &p) {
    num_serie = p.num_serie;
    cor = p.cor;
    especie = p.especie;
    peso = p.peso;
    indigestao = p.indigestao;
    resta = p.resta;
    if (p.aquario != nullptr)
        p.aquario->addPeixe(this);
    else 
        aquario = nullptr;
}

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

Peixe &Peixe::operator=(const Peixe &p) {
    if (this == &p)
        return *this;
    if (aquario)
        aquario->removePeixe(num_serie);
    num_serie = p.num_serie;
    cor = p.cor;
    especie = p.especie;
    peso = p.peso;
    indigestao = p.indigestao;
    resta = p.resta;
    if (p.aquario != nullptr)
        p.aquario->addPeixe(this);
    return *this;
}

Peixe::~Peixe() {
    if (aquario)
            aquario->removePeixe(num_serie);
        cout << "A destruir peixe\n"; 
}

ostream &operator<< (ostream &os, const Peixe &p) {
    os << p.getAsString();
    return os;
}