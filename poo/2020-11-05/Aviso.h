#ifndef AVISO_H
#define AVISO_H

#include "Prego.h"

#include <iostream>
#include <string>
using namespace std;

class Aviso {
    string msg;
    // Prego &p;
    Prego *p;
public:
    Aviso(string s, Prego *pre);
    ~Aviso();
    string getAsString() const;
    string getLocal() const;
};

#endif