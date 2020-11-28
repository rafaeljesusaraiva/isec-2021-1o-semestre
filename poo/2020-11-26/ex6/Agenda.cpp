#include "Agenda.h"

bool Agenda::repetido(const string &nome) {
    for (auto c : lista) {
        if (c->getNome() == nome)
            return true;
    }
    return false;
}

Agenda::~Agenda() {
    for (auto c : lista)
        delete c;
}

Agenda &Agenda::operator = (const Agenda &a) {
    if (this == &a) 
        return *this;
    for (auto v : lista)
        delete v;
    lista.clear();
    for (auto v : a.lista) {
        Contacto *pc = new Contacto(*v);
        lista.push_back(pc);
    }
    return *this;
}

bool Agenda::gravaAgenda(const string &nomeFich) {
    ofstream of(nomeFich);
    if (!of)
        return false;
    of << *this;
    of.close();
    return true;
}

bool Agenda::adicionaContacto(const string nome, unsigned int tel) {
    if (repetido(nome))
        return false;
    lista.push_back(new Contacto(nome, tel));
    return true;
}

string Agenda::getAsString() const {
    ostringstream os;
    for (auto c : lista)
        os << " " << c->getNome() << " " << c->getTel() << endl;
    return os.str();
}

ostream &operator << (ostream &os, const Agenda &a) {
    os << a.getAsString();
    return os;
}