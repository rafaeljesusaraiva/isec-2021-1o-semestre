#include "Aquario.h"

Aquario::~Aquario() {
    for (auto p : peixes)
        delete p;
    peixes.clear(); // redundante, porque ponteiros sao apagados
}

Peixe *Aquario::removePeixe(unsigned int n) {
    auto it = peixes.begin();
    while (it < peixes.end()) {
        if ((*it)->getNSerie() == n) {
            Peixe *out = *it;
            if (out->desligaAquario(this) == false)
                return nullptr;
            peixes.erase(it);
            return out;
        }
        ++it;
    }
    
    return nullptr;
}

void Aquario::selfClean() {
    auto it = peixes.begin();
    while (it < peixes.end()) {
        if ((*it)->isVivo()) 
            ++it;
        else {
            delete (*it);
            it = peixes.erase(it);
        }
    }
}

void Aquario::alimentaPeixes(unsigned int c) {
    auto tam = peixes.size();
    for (auto i = 0; i < tam; i++)
        peixes[i]->come(c);
}

bool Aquario::peixeExiste(unsigned int n) const {
    for (auto p : peixes)
        if (p->getNSerie() == n)
            return true;
    return false;
}

bool Aquario::addPeixe(Peixe *p) {
    if (p == nullptr || p->ligaAquario(this) == false)
        return false;
    peixes.push_back(p);
    return true;
}

string Aquario::getAsString() const {
    ostringstream os;
    if (peixes.size() == 0)
        os << "Aquario vazio.";
    else {
        os << "Peixes no aquario: \n";
        for (auto p : peixes)
            os << "  " << p->getAsString() << "\n";
    }
    return os.str();
}

ostream &operator << (ostream &os, const Aquario &a) {
    os << a.getAsString();
    return os;
}