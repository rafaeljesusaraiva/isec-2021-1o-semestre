#include "Tarifario.h"
#include <sstream>

void Tarifario::apagaTreinos() {
    duracoes.clear();
}

int Tarifario::getDuracaoTreinoI(size_t i) {
    if (i < 0 || i >= duracoes.size())
        return 0;
    return duracoes[i];
}

bool Tarifario::acrescentaTreinos(int dur) {
    if (dur < 0)
        return false;
    duracoes.push_back(dur);
    return true;
}

string Tarifario::getAsString() const {
    ostringstream os;

    if (duracoes.size() == 0)
        os << "Sem treinos a pagar";
    else {
        os << "Duracao dos treinos a pagar:";
        for (size_t i = 0; i < duracoes.size(); i++)
            os << "\n\t" << duracoes[i];
    }

    return os.str();
}

ostream &operator<< (ostream &os, const Tarifario &t) {
    os << t.getAsString();
    return os;
}