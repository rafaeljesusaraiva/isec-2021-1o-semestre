#ifndef AVISO_H
#define AVISO_H

#include <string>
#include "prego.h"
using std::string;

class Aviso
{
	string msg;
	Prego *p;

public:
	Aviso(string s, Prego *pre);
	~Aviso();

	Aviso &operator=(const Aviso &o);

	bool tiraDoPrego(Prego *p);

	string getAsString() const;
	string getLocal() const;
};
#endif

