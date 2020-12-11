#include <iostream>
#include <ctime>
#include <random>

#include "Aquario.h"
#include "Peixe.h"

using namespace std;

double getRealUniform() {
    default_random_engine e(time(0));
    uniform_real_distribution<double> d(0.0, 1.0);
    return d(e);
}

int main() {

    Peixe *p1 = new Peixe("Nemo", "azul");
    Peixe *p2 = new Peixe("Dory");
    Peixe *p3 = new Peixe("Bolhas", "amarelo");

    cout << "Peixe *p1: " << *p1 << endl;
    cout << "Peixe *p2: " << *p2 << endl;
    cout << "Peixe *p3: " << *p3 << endl;

    return 0;
}