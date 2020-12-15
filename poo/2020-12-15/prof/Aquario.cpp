#include <iostream>
#include <sstream>
#include "Aquario.h"

void Aquario::alimentaPeixes(unsigned int q) {
	vector <Peixe*> copia = peixes;
	for (auto p : copia)
		p->come(q);
}

void Aquario::selfClean() {
	auto it = peixes.begin();
	while (it < peixes.end()) {
		if ((*it)->isVivo())
			++it;
		else {
			delete (*it);
			it = peixes.erase(it);
		}
	}
}


bool Aquario::addPeixe(Peixe *p) {
	if (p == nullptr)
		return false;
	if (p->ligaAquario(this) == false)
		return false;
	peixes.push_back(p);
	return true;
}


string Aquario::getAsString() const {
	ostringstream os;
	if (peixes.size() == 0)
		os << "Aquario vazio";
	else {
		os << "Peixes no aquario: \n";
		for (auto p : peixes)
			os << "  " << *p << "\n";
	}
	return os.str();
}

ostream &operator<<(ostream &os, const Aquario &p) {
	os << p.getAsString();
	return os;
}
