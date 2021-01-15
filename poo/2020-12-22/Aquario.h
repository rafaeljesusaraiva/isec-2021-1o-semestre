#ifndef AQUARIO_H
#define AQUARIO_H

#include <vector>
#include "Peixe.h"

using namespace std;

class Aquario {
    vector<Peixe *> peixes;
public:
    Aquario() = default;
    Aquario(const Aquario &) = delete;
    ~Aquario();

    Aquario &operator= (const Aquario &) = delete;

    Peixe *removePeixe(unsigned int n);

    void selfClean();
    void alimentaPeixes(unsigned int c);

    bool peixeExiste(unsigned int n) const;
    bool addPeixe(Peixe *p);
    string getAsString() const;
};
ostream &operator<< (ostream &os, const Aquario &a);

#endif