#ifndef PIRANHA_H
#define PIRANHA_H

#include "Peixe.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*
 *  : public Peixe
 *  => significa que Piranha é classe filha de Peixe
 */
class Piranha : public Peixe {
    size_t comprimento;
public:
    // Constroi Piranha com o construtor de Peixe
    Piranha(string esp, string co="branco", size_t comp = 12) 
        : Peixe(esp+"Piranha", co), comprimento(comp) {}
    Piranha(const Piranha& p) 
        : Peixe(p), comprimento(p.comprimento) {}
    Piranha &operator= (const Piranha &p);

    virtual ~Piranha() {
        cout << "A destruir piranha " << this->getNSerie() << "\n";
    }
    
    size_t getComprimento() const { return comprimento; }
    virtual void come(unsigned int) override { setPeso(2*getPeso()); }
    virtual string getAsString() const override;
};
ostream &operator<< (ostream &os, const Piranha &p);

#endif