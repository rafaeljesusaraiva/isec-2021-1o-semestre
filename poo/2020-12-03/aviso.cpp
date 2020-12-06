#include <sstream>
#include <iostream>
#include "aviso.h"

Aviso::Aviso(string s, Prego *pre) : msg(s), p(pre) {
	p->ligaAviso(this);
	// std::cout << "construindo " << getAsString() << "\n";
}

Aviso::~Aviso() {
	p->desligaAviso(this);
	std::cout << "destruindo " << getAsString() << "\n";
}

bool Aviso::tiraDoPrego(Prego *pre) {
	if (p != pre)
		return false;
	p = nullptr;
	return true;
}

Aviso &Aviso::operator=(const Aviso &o) {
	if (this == &o)
		return *this;
	msg = o.msg;
	if (p != nullptr)
		p->desligaAviso(this);
	p = o.p;
	if (p != nullptr)
		p->ligaAviso(this);
	return *this;
}

string Aviso::getAsString() const {
	std::ostringstream os;
	os << "Aviso: " << msg << " em " << this->p->getAsString();
	return os.str();
}

string Aviso::getLocal() const {
	std::ostringstream os;
	os << "(" << this->p->getX() << "," << this->p->getY() << ")" << std::endl;
	return os.str();
}
