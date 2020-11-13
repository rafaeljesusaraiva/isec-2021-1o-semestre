#include <iostream>
#include <vector>

#include "Prego.h"
#include "Aviso.h"

using namespace std;

int main() {

    Prego p1(2,2);
    Aviso a("Aviso A", &p1);
    Aviso b("Aviso B", &p1);

    // cout << a.getAsString();
    cout << a.getLocal() << "\n";
    cout << b.getLocal() << "\n";

    p1.mudaDeSitio(50, 60);

    cout << a.getLocal() << "\n";
    cout << b.getLocal() << "\n";

    return 0;
}