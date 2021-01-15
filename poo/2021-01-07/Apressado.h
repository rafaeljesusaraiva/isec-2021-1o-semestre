#ifndef APRESSADO_H
#define APRESSADO_H

#include "Tarifario.h"
using namespace std;

class Apressado : public Tarifario {
    
protected:
public:
    virtual ~Apressado() = default;
    virtual Apressado *clone() override { return new Apressado(*this); }
    virtual int calculaPagamento() override;
    virtual string getAsString() const;
};
ostream &operator<< (ostream &os, const Apressado &t);


#endif