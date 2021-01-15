#include <sstream>
#include "Apressado.h"

int Apressado::calculaPagamento() {
    int total = 0, dur, n = getNumTreinos();

    for (int i = 0; i < n; i++) {
        dur = getDuracaoTreinoI(i);
        if (dur <= 10) total += 10;
        else if (dur <= 20) total += 15;
        else total += 25;
    }

    apagaTreinos();
    return total;
}

string Apressado::getAsString() const {
    ostringstream os;
    os << "Apressado: " << Tarifario::getAsString();
    return os.str();
}

ostream &operator<< (ostream &os, const Apressado &t) {
    os << t.getAsString();
    return os;
}