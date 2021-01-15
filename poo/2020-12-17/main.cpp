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

    Peixe *p1 = new Peixe("Dory");
    Peixe *p2 = new Piranha("Nemo", "laranja");
    Peixe *p3 = new Peixe("Dory", "amarelo");
    Peixe *p4 = new Piranha("Nemo", "laranja", 16);
    Aquario *a = new Aquario();

    a->addPeixe(p1);
    a->addPeixe(p2);
    a->addPeixe(p3);
    a->addPeixe(p4);

    cout << *a << endl;

    delete a;

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