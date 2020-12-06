#include <iostream>
#include "aviso.h"

int main()
{
    Prego p(1, 2);
    Aviso a("Aviso A", &p);
    Aviso b("Aviso B", &p);
    std::cout << a.getLocal() << "\n";
    std::cout << b.getLocal() << "\n";

    std::cout << "Avisos do prego p:\n" << p.listaAvisos();

    Prego r(21, 22);
    Aviso c("Aviso C", &r);

    std::cout << "Avisos do prego r:\n" << r.listaAvisos();

    // p.mudaDeSitio(50, 60);
    // std::cout << "Depois de mudar: \n";
    // std::cout << a.getLocal() << "\n";
    // std::cout << b.getLocal() << "\n";

    //std::cout << a.getAsString() << "\n";
}
