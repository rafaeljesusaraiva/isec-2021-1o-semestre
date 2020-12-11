#ifndef AQUARIO_H
#define AQUARIO_H

#include <vector>
#include "Peixe.h"

using namespace std;

class Aquario {
    vector<Peixe *> peixes;
public:
    Aquario() = default;
};

#endif