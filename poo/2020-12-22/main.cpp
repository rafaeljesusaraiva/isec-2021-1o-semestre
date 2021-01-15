#include <iostream>
#include <ctime>
#include <random>

#include "Peixe.h"
#include "Aquario.h"
#include "Piranha.h"

using namespace std;

double getRealUniform() {
    default_random_engine e(time(0));
    uniform_real_distribution<double> d(0.0, 1.0);
    return d(e);
}

int main() {

    Aquario *a = new Aquario();
    Piranha *p = new Piranha("Dory");
    a->addPeixe(p);
    /*
    Piranha *ppeixe = new Piranha("Nemo", "laranja");
    a->addPeixe(ppeixe);
    */
    cout << *a << endl;

    Piranha *q = new Piranha("Bolhas");
    *q = *p;
    cout << *a << endl;

    delete a;

    /*
    Peixe *ppeixe2 = new Piranha(*ppeixe);
    cout << *a << endl;
    */

    /*
    Piranha *ppir = new Piranha("Nemo", "laranja", 15);
    Peixe *ppei = new Piranha("Nemo", "laranja", 15);

    ppir->come(4);
    cout << *ppir << endl;
    ppei->come(4);
    cout << *ppei << endl;

    delete ppir;
    ppir = nullptr;
    delete ppei;
    ppei = nullptr;
    */

    /*
    Aquario *a = new Aquario();
    a->addPeixe(new Peixe("Dory"));
    a->addPeixe(new Piranha("Nemo", "laranja"));
    a->addPeixe(new Peixe("Dory", "amarelo"));
    a->addPeixe(new Piranha("Nemo", "laranja", 16));
    cout << *a << endl;

    a->alimentaPeixes(5);
    cout << *a << endl;

    delete a;
    */

    /*
    Peixe *p1 = new Peixe("Nemo", "azul");
    // cout << "Peixe *p1: " << *p1 << endl;
    Peixe *p2 = new Peixe("Dory");
    // cout << "Peixe *p2: " << *p2 << endl;
    Peixe *p3 = new Peixe("Bolhas", "amarelo");
    // cout << "Peixe *p3: " << *p3 << endl;
    Aquario *a = new Aquario();
    
    a->addPeixe(p1);
    a->addPeixe(p2);
    a->addPeixe(p3);
    cout << *a << endl;

    if (a->peixeExiste(501)) {
        cout << "Remover peixe => ";
        Peixe *removido = a->removePeixe(501);
        cout << *removido << endl;
        delete removido;
    }

    cout << *a << endl;

    // a->alimentaPeixes(45);
    // cout << *a << endl;

    // for (auto i = 0; i < 5; i++) {
    //     a->alimentaPeixes(5);
    //     cout << *a << endl;
    // }

    // a->selfClean();
    // cout << *a << endl;

    delete a;
    */
    return 0;
}