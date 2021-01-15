#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Imovel.h"

class Apartamento : public Imovel {
    int assoalhadas;
public:
    Apartamento(int area, int andar, int quartos)
        : Imovel(10*area, area, andar, "Apartamento"), assoalhadas(quartos) {}

    int getQuartos() const { return assoalhadas; }
};

#endif