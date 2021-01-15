#include <iostream>
#include "Imobiliaria.h"
#include "Apartamento.h"
#include "Loja.h"

using namespace std;

int main() {

    Imobiliaria x("ERA");
    Apartamento apartB(120, 2, 3);
    Loja lojaA(100);

    x.addImovel(&lojaA);
    x.addImovel(&apartB);

    cout << x;

    return 0;
}