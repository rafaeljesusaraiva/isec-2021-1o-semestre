#ifndef PIRANHA_H
#define PIRANHA_H

#include "Peixe.h"
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
    
    size_t getComprimento() const { return comprimento; }
};
ostream &operator<< (ostream &os, const Piranha &p);

#endif