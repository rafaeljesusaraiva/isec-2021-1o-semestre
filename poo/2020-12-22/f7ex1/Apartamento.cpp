#include "Apartamento.h"
#include <iostream>
#include <sstream>

using namespace std;

string Apartamento::getAsString() const {
    ostringstream os;
    os << Imovel::getAsString() << " || Assoalhadas: " << assoalhadas;
    return os.str();
}