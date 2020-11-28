#include "Clube.h"

Clube::Clube (unsigned int t) : tam(t) {
    if (tam < 1) 
        tam = 1;
    socios = new Pessoa * [tam];
    for (unsigned int i=0; i<tam; i++)
        socios[i] = nullptr;
}

Clube::Clube (const Clube &r) {
    socios = nullptr;
    *this = r;
}

Clube::~Clube () { 
    if (socios)
        delete []socios; 
}

Clube &Clube::operator=(const Clube &r) {
    this->tam = r.tam;
    this->nSocios = r.nSocios;
    Pessoa **copia = new Pessoa * [tam];
    for (unsigned int i = 0; i<tam; i++)
        copia[i] = r.socios[i];
    if (socios)
        delete []socios;
    this->socios = copia;
    return *this;
}

string Clube::getAsString() const {
    ostringstream os;
    os << "Capacidade: " << tam << ", n socios: " << nSocios << endl;
    os << "Socios: " << endl;
    for (unsigned int i=0; i<nSocios; i++)
        os << "\t" << *socios[i] << endl;
    return os.str();
}

bool Clube::setMembroDoClube(Pessoa * p) {
    // coloca na primeira pos livre (se houver lugar)
    if (nSocios == tam)
        return false;
    socios[nSocios] = p;
    ++nSocios;
    return true;
}