#include "Banco.h"
#include <sstream>

using namespace std;

string Banco::getAsString() const {
    ostringstream os;
    os << nome << " ";
    for (auto c : contas)
        os << "\n\t" << c.getAsString();
    return os.str();
}

// Falta: verificar se conta é valida (ex. bi unico)
bool Banco::addConta(Conta c) {
    contas.push_back(c);
    return true;
}

bool Banco::delConta(const string &bi) {
    vector<Conta>::iterator i;
    for (i=contas.begin(); i!=contas.end(); i++) {
        if (i->getTitular()->getCC() == bi) {
            i = contas.erase(i);
            return true;
        }
    }
    return false;
}

bool Banco::deposita(const string &bi, int quantia) {
    for(auto &c: contas)
        if (c.getTitular()->getCC() == bi)
            return c.deposita(quantia);
    return false;
}